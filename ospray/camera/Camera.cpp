// ospray 
#include "Camera.h"
// embree 
#include "../common/Library.h"
// stl 
#include <map>

namespace ospray {

  typedef Camera *(*creatorFct)();

  std::map<std::string, creatorFct> cameraRegistry;

  Camera *Camera::createCamera(const char *type)
  {
    std::map<std::string, Camera *(*)()>::iterator it = cameraRegistry.find(type);
    if (it != cameraRegistry.end())
      return it->second ? (it->second)() : NULL;
    
    if (ospray::logLevel >= 2) 
      std::cout << "#ospray: trying to look up camera type '" 
                << type << "' for the first time" << std::endl;

    std::string creatorName = "ospray_create_camera__"+std::string(type);
    creatorFct creator = (creatorFct)getSymbol(creatorName); //dlsym(RTLD_DEFAULT,creatorName.c_str());
    cameraRegistry[type] = creator;
    if (creator == NULL) {
      if (ospray::logLevel >= 1) 
        std::cout << "#ospray: could not find camera type '" << type << "'" << std::endl;
      return NULL;
    }
    Camera *camera = (*creator)();  camera->managedObjectType = OSP_CAMERA;
    return(camera);
  }

} // ::ospray
