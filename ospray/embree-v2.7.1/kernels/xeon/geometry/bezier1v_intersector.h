// ======================================================================== //
// Copyright 2009-2016 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include "bezier1v.h"
#include "bezier_intersector.h"

namespace embree
{
  namespace isa
  {
    /*! Intersector for a single ray with a bezier curve. */
    struct Bezier1vIntersector1
    {
      typedef Bezier1v Primitive;
      typedef Bezier1Intersector1::Precalculations Precalculations;
      
      static __forceinline void intersect(Precalculations& pre, Ray& ray, const Primitive& curve, Scene* scene, const unsigned* geomID_to_instID) {
        Bezier1Intersector1::intersect(ray,pre,curve.p0,curve.p1,curve.p2,curve.p3,curve.geomID(),curve.primID(),scene,geomID_to_instID);
      }
      
      static __forceinline bool occluded(Precalculations& pre, Ray& ray, const Primitive& curve, Scene* scene, const unsigned* geomID_to_instID) {
        return Bezier1Intersector1::occluded(ray,pre,curve.p0,curve.p1,curve.p2,curve.p3,curve.geomID(),curve.primID(),scene,geomID_to_instID);
      }
    };

    /*! Intersector for a single ray from a ray packet with a bezier curve. */
    template<int K>
      struct Bezier1vIntersectorK
    {
      typedef Bezier1v Primitive;
      typedef typename Bezier1IntersectorK<K>::Precalculations Precalculations;
      
      static __forceinline void intersect(Precalculations& pre, RayK<K>& ray, const size_t k, const Primitive& curve, Scene* scene) {
        Bezier1IntersectorK<K>::intersect(pre,ray,k,curve.p0,curve.p1,curve.p2,curve.p3,curve.geomID(),curve.primID(),scene);
      }

      static __forceinline void intersect(const vbool<K>& valid_i, Precalculations& pre, RayK<K>& ray, const Primitive& curve, Scene* scene)
      {
        int mask = movemask(valid_i);
        while (mask) intersect(pre,ray,__bscf(mask),curve,scene);
      }
 
      static __forceinline bool occluded(Precalculations& pre, RayK<K>& ray, const size_t k, const Primitive& curve, Scene* scene) {
        return Bezier1IntersectorK<K>::occluded(pre,ray,k,curve.p0,curve.p1,curve.p2,curve.p3,curve.geomID(),curve.primID(),scene);
      }

      static __forceinline vbool<K> occluded(const vbool<K>& valid_i, Precalculations& pre, RayK<K>& ray, const Primitive& curve, Scene* scene)
      {
        vbool<K> valid_o = false;
        int mask = movemask(valid_i);
        while (mask) {
          size_t k = __bscf(mask);
          if (occluded(pre,ray,k,curve,scene))
            set(valid_o, k);
        }
        return valid_o;
      }
    };
  }
}
