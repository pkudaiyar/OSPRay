OSPRay
======

This is release v1.1.1 of OSPRay. For changes and new features see the
[changelog](CHANGELOG.md). Also visit http://www.ospray.org for more
information.

OSPRay Overview
===============

OSPRay is an **o**pen source, **s**calable, and **p**ortable **ray**
tracing engine for high-performance, high-fidelity visualization on
Intel® Architecture CPUs. OSPRay is released under the permissive
[Apache 2.0 license](http://www.apache.org/licenses/LICENSE-2.0).

The purpose of OSPRay is to provide an open, powerful, and easy-to-use
rendering library that allows one to easily build applications that use
ray tracing based rendering for interactive applications (including both
surface- and volume-based visualizations). OSPRay is completely
CPU-based, and runs on anything from laptops, to workstations, to
compute nodes in HPC systems.

OSPRay internally builds on top of [Embree](https://embree.github.io/)
and [ISPC (Intel® SPMD Program Compiler)](https://ispc.github.io/), and
fully utilizes modern instruction sets like Intel® SSE, AVX, AVX2, and
AVX-512 to achieve high rendering performance.

OSPRay Support and Contact
--------------------------

OSPRay is under active development, and though we do our best to
guarantee stable release versions a certain number of bugs,
as-yet-missing features, inconsistencies, or any other issues are still
possible. Should you find any such issues please report them immediately
via [OSPRay's GitHub Issue
Tracker](https://github.com/ospray/OSPRay/issues) (or, if you should
happen to have a fix for it,you can also send us a pull request); for
missing features please contact us via email at
<ospray@googlegroups.com>.

For recent news, updates, and announcements, please see our complete
[news/updates](http://www.ospray.org/news.html) page.

Join our [mailing
list](https://groups.google.com/forum/#!forum/ospray-announce/join) to
receive release announcements and major news regarding OSPRay.

Building OSPRay from Source
===========================

The latest OSPRay sources are always available at the [OSPRay GitHub
repository](http://github.com/ospray/ospray). The default `master`
branch should always point to the latest tested bugfix release.

Prerequisites
-------------

OSPRay currently supports both Linux and Mac OS X (and experimentally
Windows). In addition, before you can build OSPRay you need the
following prerequisites:

-   You can clone the latest OSPRay sources via:

        git clone https://github.com/ospray/ospray.git

-   To build OSPRay you need [CMake](http://www.cmake.org), any form of
    C++11 compiler (we recommend using the [Intel® C++
    compiler (icc)](https://software.intel.com/en-us/c-compilers), but
    also support GCC and Clang), and standard Linux development tools.
    To build the demo viewers, you should also have some version of
    OpenGL and the GL Utility Toolkit (GLUT or freeglut), as well as Qt
    4.6 or higher.
-   Additionally you require a copy of the [Intel® SPMD Program
    Compiler (ISPC)](http://ispc.github.io). Please obtain a copy of the
    latest binary release of ISPC (currently 1.9.1) from the [ISPC
    downloads page](https://ispc.github.io/downloads.html). The build
    system looks for ISPC in the `PATH` and in the directory right "next
    to" the checked-out OSPRay sources.[^1] Alternatively set the CMake
    variable `ISPC_EXECUTABLE` to the location of the ISPC compiler.
-   Per default OSPRay uses the [Intel® Threading Building
    Blocks](https://www.threadingbuildingblocks.org/) (TBB) as tasking
    system, which we recommend for performance and flexibility reasons.
    Alternatively you can set CMake variable `OSPRAY_TASKING_SYSTEM` to
    `OpenMP`, `Internal`, or `Cilk` (icc only).
-   OSPRay also heavily uses [Embree](https://embree.github.io/),
    installing version 2.12 is recommended. If Embree is not found by
    CMake its location can be hinted with the variable `embree_DIR`. As
    a fallback OSPRay also includes its own copy of Embree.

Depending on your Linux distribution you can install these dependencies
using `yum` or `apt-get`. Some of these packages might already be
installed or might have slightly different names.

Type the following to install the dependencies using `yum`:

    sudo yum install cmake.x86_64
    sudo yum install tbb.x86_64 tbb-devel.x86_64
    sudo yum install freeglut.x86_64 freeglut-devel.x86_64
    sudo yum install qt-devel.x86_64

Type the following to install the dependencies using `apt-get`:

    sudo apt-get install cmake-curses-gui
    sudo apt-get install libtbb-dev
    sudo apt-get install freeglut3-dev
    sudo apt-get install libqt4-dev

Under Mac OS X these dependencies can be installed using
[MacPorts](http://www.macports.org/):

    sudo port install cmake tbb freeglut qt4

Compiling OSPRay
----------------

Assume the above requisites are all fulfilled, building OSPRay through
CMake is easy:

-   Create a build directory, and go into it

        user@mymachine[~/Projects]: mkdir ospray/release
        user@mymachine[~/Projects]: cd ospray/release

    (We do recommend having separate build directories for different
    configurations such as release, debug, etc).

-   The compiler CMake will use will default to whatever the `CC` and
    `CXX` environment variables point to. Should you want to specify a
    different compiler, run cmake manually while specifying the
    desired compiler. The default compiler on most linux machines is
    `gcc`, but it can be pointed to `clang` instead by executing the
    following:

        user@mymachine[~/Projects/ospray/release]: cmake
            -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang ..

    CMake will now use Clang instead of GCC. If you are ok with using
    the default compiler on your system, then simply skip this step.
    Note that the compiler variables cannot be changed after the first
    `cmake` or `ccmake` run.

-   Open the CMake configuration dialog

        user@mymachine[~/Projects/ospray/release]: ccmake ..

-   Make sure to properly set build mode and enable the components you
    need, etc; then type 'c'onfigure and 'g'enerate. When back on the
    command prompt, build it using

        user@mymachine[~/Projects/ospray/release]: make

-   You should now have `libospray.so` as well as a set of
    sample viewers. You can test your version of OSPRay using any of the
    examples on the [OSPRay Demos and
    Examples](http://www.ospray.org/demos.html) page.

Documentation
=============

The following [API
documentation](http://www.sdvis.org/ospray/download/OSPRay_readme.pdf "OSPRay Documentation")
of OSPRay can also be found as a [pdf
document](http://www.sdvis.org/ospray/download/OSPRay_readme.pdf "OSPRay Documentation")
(2.6MB).

For a deeper explanation of the concepts, design, features and
performance of OSPRay also have a look at the IEEE Vis 2016 paper
"[OSPRay – A CPU Ray Tracing Framework for Scientific
Visualization](http://www.sdvis.org/ospray/download/talks/IEEEVis2016_OSPRay_paper.pdf)"
(49MB, or get the [smaller
version](http://www.sdvis.org/ospray/download/talks/IEEEVis2016_OSPRay_paper_small.pdf)
1.8MB). Also available are the [slides of the
talk](http://www.sdvis.org/ospray/download/talks/IEEEVis2016_OSPRay_talk.pdf)
(5.2MB).

OSPRay API
==========

To access the OSPRay API you first need to include the OSPRay header

``` {.cpp}
#include "ospray/ospray.h"
```

The API is compatible with C99 and C++. Then initialize the OSPRay
rendering engine with

``` {.cpp}
void ospInit(int *argc, const char **argv);
```

OSPRay parses (and removes) its known command line parameters, so you
could just pass `argc` and `argv` from you application's `main`
function. For an example see the [tutorial](#tutorial). The following
parameters (which are prefixed by convention with "`--osp:`") are
understood:

<table style="width:97%;">
<caption>Command line parameters accepted by OSPRay's <code>ospInit</code>.</caption>
<colgroup>
<col width="33%" />
<col width="63%" />
</colgroup>
<thead>
<tr class="header">
<th align="left">Parameter</th>
<th align="left">Description</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td align="left"><code>--osp:debug</code></td>
<td align="left">enables various extra checks and debug output, and disables multi-threading</td>
</tr>
<tr class="even">
<td align="left"><code>--osp:numthreads &lt;n&gt;</code></td>
<td align="left">use <code>n</code> threads instead of per default using all detected hardware threads</td>
</tr>
<tr class="odd">
<td align="left"><code>--osp:loglevel &lt;n&gt;</code></td>
<td align="left">set logging level, default <code>0</code>; increasing <code>n</code> means increasingly verbose log messages</td>
</tr>
<tr class="even">
<td align="left"><code>--osp:verbose</code></td>
<td align="left">shortcut for <code>--osp:loglevel 1</code></td>
</tr>
<tr class="odd">
<td align="left"><code>--osp:vv</code></td>
<td align="left">shortcut for <code>--osp:loglevel 2</code></td>
</tr>
<tr class="even">
<td align="left"><code>--osp:mpi</code></td>
<td align="left">enables MPI mode for parallel rendering, to be used in conjunction with <code>mpirun</code></td>
</tr>
</tbody>
</table>

: Command line parameters accepted by OSPRay's `ospInit`.

As an alternative to command line parameters (which still have
precedence) OSPRay can also be configured by environment variables
(which are prefixed by convention with "`OSPRAY_`"):

| Variable           | Description                      |
|:-------------------|:---------------------------------|
| OSPRAY\_THREADS    | equivalent to `--osp:numthreads` |
| OSPRAY\_LOG\_LEVEL | equivalent to `--osp:loglevel`   |

: Environment variables interpreted by OSPRay.

OSPRay's functionality can be extended via plugins, which are
implemented in shared libraries. To load plugin `name` from
`libospray_module_<name>.so` (on Linux and Mac OS X) or
`ospray_module_<name>.dll` (on Windows) use

``` {.cpp}
int32_t ospLoadModule(const char *name);
```

Modules are searched in OS-dependent paths, which include the
application directory. `ospLoadModule` returns `0` if the plugin could
be loaded and an error code `> 0` otherwise.

Objects
-------

All entities of OSPRay (the renderer, volumes, geometries, lights,
cameras, ...) are a specialization of `OSPObject` and share common
mechanism to deal with parameters and lifetime.

An important aspect of object parameters is that parameters do not get
passed to objects immediately. Instead, parameters are not visible at
all to objects until they get explicitly committed to a given object via
a call to

``` {.cpp}
void ospCommit(OSPObject);
```

at which time all previously additions or changes to parameters are
visible at the same time. If a user wants to change the state of an
existing object (e.g., to change the origin of an already existing
camera) it is perfectly valid to do so, as long as the changed
parameters are recommitted.

The commit semantic allow for batching up multiple small changes, and
specifies exactly when changes to objects will occur. This is important
to ensure performance and consistency for devices crossing a PCI bus, or
across a network. In our MPI implementation, for example, we can easily
guarantee consistency among different nodes by MPI barrier’ing on every
commit.

Note that OSPRay uses reference counting to manage the lifetime of all
objects, so one cannot explicitly "delete" any object. Instead, to
indicate that the application does not need and does not access the
given object anymore, call

``` {.cpp}
void ospRelease(OSPObject);
```

This decreases its reference count and if the count reaches `0` the
object will automatically get deleted.

### Parameters

Parameters allow to configure the behavior of and to pass data to
objects. However, objects do *not* have an explicit interface for
reasons of high flexibility and a more stable compile-time API. Instead,
parameters are passed separately to objects in an arbitrary order, and
unknown parameters will simply be ignored. The following functions allow
adding various types of parameters with name `id` to a given object:

``` {.cpp}
// add a C-string (zero-terminated char *) parameter
void ospSetString(OSPObject, const char *id, const char *s);

// add an object handle parameter to another object
void ospSetObject(OSPObject, const char *id, OSPObject object);

// add an untyped pointer -- this will *ONLY* work in local rendering!
void ospSetVoidPtr(OSPObject, const char *id, void *v);

// add scalar and vector integer and float parameters
void ospSetf  (OSPObject, const char *id, float x);
void ospSet1f (OSPObject, const char *id, float x);
void ospSet1i (OSPObject, const char *id, int32_t x);
void ospSet2f (OSPObject, const char *id, float x, float y);
void ospSet2fv(OSPObject, const char *id, const float *xy);
void ospSet2i (OSPObject, const char *id, int x, int y);
void ospSet2iv(OSPObject, const char *id, const int *xy);
void ospSet3f (OSPObject, const char *id, float x, float y, float z);
void ospSet3fv(OSPObject, const char *id, const float *xyz);
void ospSet3i (OSPObject, const char *id, int x, int y, int z);
void ospSet3iv(OSPObject, const char *id, const int *xyz);
void ospSet4f (OSPObject, const char *id, float x, float y, float z, float w);
void ospSet4fv(OSPObject, const char *id, const float *xyzw);

// additional functions to pass vector integer and float parameters in C++
void ospSetVec2f(OSPObject, const char *id, const vec2f &v);
void ospSetVec2i(OSPObject, const char *id, const vec2i &v);
void ospSetVec3f(OSPObject, const char *id, const vec3f &v);
void ospSetVec3i(OSPObject, const char *id, const vec3i &v);
void ospSetVec4f(OSPObject, const char *id, const vec4f &v);
```

### Data

There is also the possibility to aggregate many values of the same type
into an array, which then itself can be used as a parameter to objects.
To create such a new data buffer, holding `numItems` elements of the
given type, from the initialization data pointed to by `source` and
optional creation flags, use

``` {.cpp}
OSPData ospNewData(size_t numItems,
                   OSPDataType,
                   const void *source,
                   const uint32_t dataCreationFlags = 0);
```

The call returns an `OSPData` handle to the created array. The flag
`OSP_DATA_SHARED_BUFFER` indicates that the buffer can be shared with
the application. In this case the calling program guarantees that the
`source` pointer will remain valid for the duration that this data array
is being used. The enum type `OSPDataType` describes the different data
types that can be represented in OSPRay; valid constants are listed in
the table below.

| Type/Name               | Description                                   |
|:------------------------|:----------------------------------------------|
| OSP\_VOID\_PTR          | void pointer                                  |
| OSP\_DATA               | data reference                                |
| OSP\_OBJECT             | generic object reference                      |
| OSP\_CAMERA             | camera object reference                       |
| OSP\_FRAMEBUFFER        | framebuffer object reference                  |
| OSP\_LIGHT              | light object reference                        |
| OSP\_MATERIAL           | material object reference                     |
| OSP\_TEXTURE            | texture object reference                      |
| OSP\_RENDERER           | renderer object reference                     |
| OSP\_MODEL              | model object reference                        |
| OSP\_GEOMETRY           | geometry object reference                     |
| OSP\_VOLUME             | volume object reference                       |
| OSP\_TRANSFER\_FUNCTION | transfer function object reference            |
| OSP\_PIXEL\_OP          | pixel operation object reference              |
| OSP\_STRING             | C-style zero-terminated character string      |
| OSP\_CHAR               | 8 bit signed character scalar                 |
| OSP\_UCHAR              | 8 bit unsigned character scalar               |
| OSP\_UCHAR\[234\]       | ... and \[234\]-element vector                |
| OSP\_USHORT             | 16 bit unsigned integer scalar                |
| OSP\_INT                | 32 bit signed integer scalar                  |
| OSP\_INT\[234\]         | ... and \[234\]-element vector                |
| OSP\_UINT               | 32 bit unsigned integer scalar                |
| OSP\_UINT\[234\]        | ... and \[234\]-element vector                |
| OSP\_LONG               | 64 bit signed integer scalar                  |
| OSP\_LONG\[234\]        | ... and \[234\]-element vector                |
| OSP\_ULONG              | 64 bit unsigned integer scalar                |
| OSP\_ULONG\[234\]       | ... and \[234\]-element vector                |
| OSP\_FLOAT              | 32 bit single precision floating point scalar |
| OSP\_FLOAT\[234\]       | ... and \[234\]-element vector                |
| OSP\_FLOAT3A            | ... and aligned 3-element vector              |
| OSP\_DOUBLE             | 64 bit double precision floating point scalar |

: Valid named constants for `OSPDataType`.

To add a data array as parameter named `id` to another object call

``` {.cpp}
void ospSetData(OSPObject, const char *id, OSPData);
```

Volumes
-------

Volumes are volumetric datasets with discretely sampled values in 3D
space, typically a 3D scalar field. To create a new volume object of
given type `type` use

``` {.cpp}
OSPVolume ospNewVolume(const char *type);
```

The call returns `NULL` if that type of volume is not known by OSPRay,
or else an `OSPVolume` handle.

### Structured Volume

Structured volumes only need to store the values of the samples, because
their addresses in memory can be easily computed from a 3D position. A
common type of structured volumes are regular grids. OSPRay supports two
variants that differ in how the volumetric data for the regular grids is
specified.

The first variant shares the voxel data with the application. Such a
volume type is created by passing the type string
"`shared_structured_volume`" to `ospNewVolume`. The voxel data is laid
out in memory in XYZ order and provided to the volume via a
[data](#data) buffer parameter named "`voxelData`".

The second regular grid variant is optimized for rendering performance:
data locality in memory is increased by arranging the voxel data in
smaller blocks. This volume type is created by passing the type string
"`block_bricked_volume`" to `ospNewVolume`. Because of this
rearrangement of voxel data it cannot be shared the with the application
anymore, but has to be transferred to OSPRay via

``` {.cpp}
int ospSetRegion(OSPVolume, void *source,
                            const vec3i &regionCoords,
                            const vec3i &regionSize);
```

The voxel data pointed to by `source` is copied into the given volume
starting at position `regionCoords`, must be of size `regionSize` and be
placed in memory in XYZ order. Note that OSPRay distinguishes between
volume data and volume parameters. This function must be called only
after all volume parameters (in particular `dimensions` and `voxelType`,
see below) have been set and *before* `ospCommit(volume)` is called.
Memory for the volume is allocated on the first call to this function.
If allocation is unsuccessful or the region size is invalid, the return
value is `0`, and non-zero otherwise.

The common parameters understood by both structured volume variants are
summarized in the table below. If `voxelRange` is not provided for a
volume OSPRay will compute it based on the voxel data, which may result
in slower data updates.

| Type   | Name        | Description                                                |
|:-------|:------------|:-----------------------------------------------------------|
| vec3i  | dimensions  | number of voxels in each dimension $(x, y, z)$             |
| string | voxelType   | data type of each voxel, currently supported are:          |
|       |            | "uchar" (8 bit unsigned integer)                           |
|       |            | "ushort" (16 bit unsigned integer)                         |
|       |            | "float" (32 bit single precision floating point)           |
|       |            | "double" (64 bit double precision floating point)          |
| vec2f  | voxelRange  | minimum and maximum of the scalar values                   |
| vec3f  | gridOrigin  | origin of the grid in world-space, default $(0, 0, 0)$     |
| vec3f  | gridSpacing | size of the grid cells in world-space, default $(1, 1, 1)$ |

: Parameters to configure a structured volume.

### Transfer Function

Transfer functions map the scalar values of volumes to color and opacity
and thus they can be used to visually emphasize certain features of the
volume. To create a new transfer function of given type `type` use

``` {.cpp}
OSPTransferFunction ospNewTransferFunction(const char *type);
```

The call returns `NULL` if that type of transfer functions is not known
by OSPRay, or else an `OSPTransferFunction` handle to the created
transfer function. That handle can be assigned to a volume as parameter
"`transferFunction`" using `ospSetObject`.

One type of transfer function that is built-in in OSPRay is the linear
transfer function, which interpolates between given equidistant colors
and opacities. It is create by passing the string "`piecewise_linear`"
to `ospNewTransferFunction` and it is controlled by these parameters:

| Type      | Name       | Description                                   |
|:----------|:-----------|:----------------------------------------------|
| vec3f\[\] | colors     | [data](#data) array of RGB colors             |
| float\[\] | opacities  | [data](#data) array of opacities              |
| vec2f     | valueRange | domain (scalar range) this function maps from |

: Parameters accepted by the linear transfer function.

Geometries
----------

Geometries in OSPRay are objects that describe surfaces. To create a new
geometry object of given type `type` use

``` {.cpp}
OSPGeometry ospNewGeometry(const char *type);
```

The call returns `NULL` if that type of geometry is not known by OSPRay,
or else an `OSPGeometry` handle.

### Triangle Mesh

A traditional triangle mesh (indexed face set) geometry is created by
calling `ospNewGeometry` with type string "`triangles`". Once created, a
triangle mesh recognizes the following parameters:

| Type         | Name            | Description                                              |
|:-------------|:----------------|:---------------------------------------------------------|
| vec3f(a)\[\] | vertex          | [data](#data) array of vertex positions                  |
| vec3f(a)\[\] | vertex.normal   | [data](#data) array of vertex normals                    |
| vec4f\[\]    | vertex.color    | [data](#data) array of vertex colors (RGBA)              |
| vec2f\[\]    | vertex.texcoord | [data](#data) array of vertex texture coordinates        |
| vec3i(a)\[\] | index           | [data](#data) array of triangle indices (into vertex.\*) |

: Parameters defining a triangle mesh geometry.

### Spheres

A geometry consisting of individual spheres, each of which can have an
own radius, is created by calling `ospNewGeometry` with type string
"`spheres`". The spheres will not be tessellated but rendered
procedurally and are thus perfectly round. To allow a variety of sphere
representations in the application this geometry allows a flexible way
of specifying the data of center position and radius within a
[data](#data) array:

<table style="width:97%;">
<caption>Parameters defining a spheres geometry.</caption>
<colgroup>
<col width="12%" />
<col width="22%" />
<col width="13%" />
<col width="48%" />
</colgroup>
<thead>
<tr class="header">
<th align="left">Type</th>
<th align="left">Name</th>
<th align="right">Default</th>
<th align="left">Description</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td align="left">float</td>
<td align="left">radius</td>
<td align="right">0.01</td>
<td align="left">radius of all spheres (if <code>offset_radius</code> is not used)</td>
</tr>
<tr class="even">
<td align="left">OSPData</td>
<td align="left">spheres</td>
<td align="right">NULL</td>
<td align="left">memory holding the <a href="#data">data</a> of all spheres</td>
</tr>
<tr class="odd">
<td align="left">int</td>
<td align="left">bytes_per_sphe re</td>
<td align="right">16</td>
<td align="left">size (in bytes) of each sphere within the <code>spheres</code> array</td>
</tr>
<tr class="even">
<td align="left">int</td>
<td align="left">offset_center</td>
<td align="right">0</td>
<td align="left">offset (in bytes) of each sphere's &quot;vec3f center&quot; position (in object-space) within the <code>spheres</code> array</td>
</tr>
<tr class="odd">
<td align="left">int</td>
<td align="left">offset_radius</td>
<td align="right">-1</td>
<td align="left">offset (in bytes) of each sphere's &quot;float radius&quot; within the <code>spheres</code> array (<code>-1</code> means disabled and use <code>radius</code>)</td>
</tr>
</tbody>
</table>

: Parameters defining a spheres geometry.

### Cylinders

A geometry consisting of individual cylinders, each of which can have an
own radius, is created by calling `ospNewGeometry` with type string
"`cylinders`". The cylinders will not be tessellated but rendered
procedurally and are thus perfectly round. To allow a variety of
cylinder representations in the application this geometry allows a
flexible way of specifying the data of offsets for start position, end
position and radius within a [data](#data) array. All parameters are
listed in the table below.

<table style="width:97%;">
<caption>Parameters defining a cylinders geometry.</caption>
<colgroup>
<col width="12%" />
<col width="25%" />
<col width="13%" />
<col width="46%" />
</colgroup>
<thead>
<tr class="header">
<th align="left">Type</th>
<th align="left">Name</th>
<th align="right">Default</th>
<th align="left">Description</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td align="left">float</td>
<td align="left">radius</td>
<td align="right">0.01</td>
<td align="left">radius of all cylinders (if <code>offset_radius</code> is not used)</td>
</tr>
<tr class="even">
<td align="left">OSPData</td>
<td align="left">cylinders</td>
<td align="right">NULL</td>
<td align="left">memory holding the <a href="#data">data</a> of all cylinders</td>
</tr>
<tr class="odd">
<td align="left">int</td>
<td align="left">bytes_per_cylind er</td>
<td align="right">28</td>
<td align="left">size (in bytes) of each cylinder within the <code>cylinders</code> array</td>
</tr>
<tr class="even">
<td align="left">int</td>
<td align="left">offset_v0</td>
<td align="right">0</td>
<td align="left">offset (in bytes) of each cylinder's &quot;vec3f v0&quot; position (the start vertex, in object-space) within the <code>cylinders</code> array</td>
</tr>
<tr class="odd">
<td align="left">int</td>
<td align="left">offset_v1</td>
<td align="right">12</td>
<td align="left">offset (in bytes) of each cylinder's &quot;vec3f v1&quot; position (the end vertex, in object-space) within the <code>cylinders</code> array</td>
</tr>
<tr class="even">
<td align="left">int</td>
<td align="left">offset_radius</td>
<td align="right">-1</td>
<td align="left">offset (in bytes) of each cylinder's &quot;float radius&quot; within the <code>cylinders</code> array (<code>-1</code> means disabled and use <code>radius</code> instead)</td>
</tr>
</tbody>
</table>

: Parameters defining a cylinders geometry.

### Streamlines

A geometry consisting of multiple stream lines of constant radius is
created by calling `ospNewGeometry` with type string "`streamlines`".
The stream lines are internally assembled from connected (and rounded)
cylinder segments and are thus perfectly round. The parameters defining
this geometry are listed in the table below.

| Type       | Name         | Description                                                  |
|:-----------|:-------------|:-------------------------------------------------------------|
| float      | radius       | radius of all stream lines, default 0.01                     |
| vec3fa\[\] | vertex       | [data](#data) array of all vertices for *all* stream lines   |
| vec3fa\[\] | vertex.color | [data](#data) array of corresponding vertex colors           |
| int32\[\]  | index        | [data](#data) array of indices to the first vertex of a link |

: Parameters defining a streamlines geometry.

Each stream line is specified by a set of (aligned) vec3fa control
points in `vertex`; all vertices belonging to to the same logical stream
line are connected via [cylinders](#cylinders) of a fixed radius
`radius`, with additional [spheres](#spheres) at each vertex to make for
a smooth transition between the cylinders.

A streamlines geometry can contain multiple disjoint stream lines, each
streamline is specified as a list of linear segments (or links)
referenced via `index`: each entry `e` of the `index` array points the
first vertex of a link (`vertex[index[e]]`) and the second vertex of the
link is implicitly the directly following one (`vertex[index[e]+1]`).
For example, two stream lines of vertices `(A-B-C-D)` and `(E-F-G)`,
respectively, would internally correspond to five links (`A-B`, `B-C`,
`C-D`, `E-F`, and `F-G`), and would be specified via an array of
vertices `[A,B,C,D,E,F,G]`, plus an array of link indices `[0,1,2,4,5]`.

### Isosurfaces

OSPRay can directly render multiple isosurfaces of a volume without
first tessellating them. To do so create an isosurfaces geometry by
calling `ospNewGeometry` with type string "`isosurfaces`". Each
isosurface will be colored according to the provided volume's [transfer
function](#transfer-function).

| Type      | Name      | Description                                        |
|:----------|:----------|:---------------------------------------------------|
| float\[\] | isovalues | [data](#data) array of isovalues                   |
| OSPVolume | volume    | handle of the [volume](#volumes) to be isosurfaced |

: Parameters defining an isosurfaces geometry.

### Slices

One tool to highlight interesting features of volumetric data is to
visualize 2D cuts (or slices) by placing planes into the volume. Such a
slices geometry is created by calling `ospNewGeometry` with type string
"`slices`". The planes are defined by the coefficients $(a,b,c,d)$ of
the plane equation $ax + by + cz + d = 0$. Each slice is colored
according to the provided volume's [transfer
function](#transfer-function).

| Type      | Name   | Description                                                |
|:----------|:-------|:-----------------------------------------------------------|
| vec4f\[\] | planes | [data](#data) array with plane coefficients for all slices |
| OSPVolume | volume | handle of the [volume](#volumes) that will be sliced       |

: Parameters defining a slices geometry.

### Instances

OSPRay supports instancing via a special type of geometry. Instances are
created by transforming another given [model](#model)
`modelToInstantiate` with the given affine transformation `transform` by
calling

``` {.cpp}
OSPGeometry ospNewInstance(OSPModel modelToInstantiate, const affine3f &transform);
```

Renderer
--------

A renderer is the central object for rendering in OSPRay. Different
renderers implement different features and support different materials.
To create a new renderer of given type `type` use

``` {.cpp}
OSPRenderer ospNewRenderer(const char *type);
```

The call returns `NULL` if that type of renderer is not known, or else
an `OSPRenderer` handle to the created renderer. General parameters of
all renderers are

| Type         | Name              | Description                                               |
|:-------------|:------------------|:----------------------------------------------------------|
| OSPModel     | model             | the [model](#model) to render                             |
| OSPCamera    | camera            | the [camera](#cameras) to be used for rendering           |
| OSPLight\[\] | lights            | [data](#data) array with handles of the [lights](#lights) |
| float        | epsilon           | ray epsilon to avoid self-intersections, default 10^-6^   |
| int          | spp               | samples per pixel, default 1                              |
| int          | maxDepth          | maximum ray recursion depth                               |
| float        | varianceThreshold | threshold for adaptive accumulation                       |

: Parameters understood by all renderers.

OSPRay's renderers support a feature called adaptive accumulation, which
accelerates progressive [rendering](#rendering) by stopping the
rendering and refinement of image regions that have an estimated
variance below the `varianceThreshold`. This feature requires a
[framebuffer](#framebuffer) with an `OSP_FB_VARIANCE` channel.

### SciVis Renderer

The SciVis renderer is a fast ray tracer for scientific visualization
which supports volume rendering and ambient occlusion. It is created by
passing the type string "`scivis`" or "`raytracer`" to `ospNewRenderer`.
In addition to the [general parameters](#renderer) understood by all
renderers the SciVis renderer supports the following special parameters:

<table style="width:97%;">
<caption>Special parameters understood by the SciVis renderer.</caption>
<colgroup>
<col width="17%" />
<col width="26%" />
<col width="13%" />
<col width="39%" />
</colgroup>
<thead>
<tr class="header">
<th align="left">Type</th>
<th align="left">Name</th>
<th align="right">Default</th>
<th align="left">Description</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td align="left">bool</td>
<td align="left">shadowsEnabled</td>
<td align="right">false</td>
<td align="left">whether to compute (hard) shadows</td>
</tr>
<tr class="even">
<td align="left">int</td>
<td align="left">aoSamples</td>
<td align="right">0</td>
<td align="left">number of rays per sample to compute ambient occlusion</td>
</tr>
<tr class="odd">
<td align="left">float</td>
<td align="left">aoOcclusionDistanc e</td>
<td align="right">10<sup>20</sup></td>
<td align="left">maximum distance to consider for ambient occlusion</td>
</tr>
<tr class="even">
<td align="left">float</td>
<td align="left">aoWeight</td>
<td align="right">0.25</td>
<td align="left">amount of ambient occlusion added in shading</td>
</tr>
<tr class="odd">
<td align="left">bool</td>
<td align="left">oneSidedLighting</td>
<td align="right">true</td>
<td align="left">if true back-facing surfaces (wrt. light) receive no illumination</td>
</tr>
<tr class="even">
<td align="left">vec3f</td>
<td align="left">bgColor</td>
<td align="right">white</td>
<td align="left">background color (RGB)</td>
</tr>
<tr class="odd">
<td align="left">bool</td>
<td align="left">backgroundEnabled</td>
<td align="right">true</td>
<td align="left">whether to color the background with <code>bgColor</code></td>
</tr>
<tr class="even">
<td align="left">OSPTexture2D</td>
<td align="left">maxDepthTexture</td>
<td align="right">NULL</td>
<td align="left">screen-sized float <a href="#texture">texture</a> with maximum far distance per pixel</td>
</tr>
</tbody>
</table>

: Special parameters understood by the SciVis renderer.

The SciVis renderer supports depth composition with images of other
renderers, for example to incorporate help geometries of a 3D UI that
were rendered with OpenGL. The screen-sized [texture](#texture)
`maxDepthTexture` must have format `OSP_TEXTURE_R32F` and flag
`OSP_TEXTURE_FILTER_NEAREST`. The fetched values are used to limit the
distance of primary rays, thus objects of other renderers can hide
objects rendered by OSPRay.

### Path tracer

The path tracer supports soft shadows, indirect illumination and
realistic materials. In addition to the [general parameters](#renderer)
understood by all renderers the path tracer supports the following
special parameters:

<table style="width:97%;">
<caption>Special parameters understood by the path tracer.</caption>
<colgroup>
<col width="17%" />
<col width="21%" />
<col width="13%" />
<col width="44%" />
</colgroup>
<thead>
<tr class="header">
<th align="left">Type</th>
<th align="left">Name</th>
<th align="right">Default</th>
<th align="left">Description</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td align="left">float</td>
<td align="left">minContribution</td>
<td align="right">0.01</td>
<td align="left">sample contributions below this value will be neglected to speed-up rendering</td>
</tr>
<tr class="even">
<td align="left">float</td>
<td align="left">maxContribution</td>
<td align="right">∞</td>
<td align="left">samples are clamped to this value before they are accumulated into the framebuffer</td>
</tr>
<tr class="odd">
<td align="left">OSPTexture2D</td>
<td align="left">backplate</td>
<td align="right">NULL</td>
<td align="left"><a href="#texture">texture</a> image used as background, replacing visible lights in infinity (e.g. the <a href="#hdri-light">HDRI light</a>)</td>
</tr>
</tbody>
</table>

: Special parameters understood by the path tracer.

### Model

Models are a container of scene data. They can hold the different
[geometries](#geometries) and [volumes](#volumes) as well as references
to (and [instances](#instances) of) other models. A model is associated
with a single logical acceleration structure. To create an (empty) model
call

``` {.cpp}
OSPModel ospNewModel();
```

The call returns an `OSPModel` handle to the created model. To add an
already created geometry or volume to a model use

``` {.cpp}
void ospAddGeometry(OSPModel, OSPGeometry);
void ospAddVolume(OSPModel, OSPVolume);
```

An existing geometry or volume can be removed from a model with

``` {.cpp}
void ospRemoveGeometry(OSPModel, OSPGeometry);
void ospRemoveVolume(OSPModel, OSPVolume);
```

### Lights

To let the given `renderer` create a new light source of given type
`type` use

``` {.cpp}
OSPLight ospNewLight(OSPRenderer renderer, const char *type);
```

The call returns `NULL` if that type of camera is not known by the
renderer, or else an `OSPLight` handle to the created light source. All
light sources[^2] accept the following parameters:

| Type     | Name      | Description                       |
|:---------|:----------|:----------------------------------|
| vec3f(a) | color     | color of the light                |
| float    | intensity | intensity of the light (a factor) |

: Parameters accepted by the all lights.

The following light types are supported by most OSPRay renderers.

#### Directional Light / Distant Light

The distant light (or traditionally the directional light) is thought to
be very far away (outside of the scene), thus its light arrives (almost)
as parallel rays. It is created by passing the type string "`distant`"
to `ospNewLight`. In addition to the [general parameters](#lights)
understood by all lights the distant light supports the following
special parameters:

| Type     | Name            | Description                                  |
|:---------|:----------------|:---------------------------------------------|
| vec3f(a) | direction       | main emission direction of the distant light |
| float    | angularDiameter | apparent size (angle in degree) of the light |

: Special parameters accepted by the distant light.

Setting the angular diameter to a value greater than zero will result in
soft shadows when the renderer uses stochastic sampling (like the [path
tracer](#path-tracer)). For instance, the apparent size of the sun is
about 0.53°.

#### Point Light / Sphere Light

The sphere light (or the special case point light) is a light emitting
uniformly in all directions. It is created by passing the type string
"`sphere`" to `ospNewLight`. In addition to the [general
parameters](#lights) understood by all lights the sphere light supports
the following special parameters:

| Type     | Name     | Description                                    |
|:---------|:---------|:-----------------------------------------------|
| vec3f(a) | position | the center of the sphere light, in world-space |
| float    | radius   | the size of the sphere light                   |

: Special parameters accepted by the sphere light.

Setting the radius to a value greater than zero will result in soft
shadows when the renderer uses stochastic sampling (like the [path
tracer](#path-tracer)).

#### Spot Light

The spot light is a light emitting into a cone of directions. It is
created by passing the type string "`spot`" to `ospNewLight`. In
addition to the [general parameters](#lights) understood by all lights
the spot light supports the special parameters listed in the table.

<table style="width:97%;">
<caption>Special parameters accepted by the spot light.</caption>
<colgroup>
<col width="13%" />
<col width="20%" />
<col width="63%" />
</colgroup>
<thead>
<tr class="header">
<th align="left">Type</th>
<th align="left">Name</th>
<th align="left">Description</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td align="left">vec3f(a)</td>
<td align="left">position</td>
<td align="left">the center of the spot light, in world-space</td>
</tr>
<tr class="even">
<td align="left">vec3f(a)</td>
<td align="left">direction</td>
<td align="left">main emission direction of the spot</td>
</tr>
<tr class="odd">
<td align="left">float</td>
<td align="left">openingAngle</td>
<td align="left">full opening angle (in degree) of the spot; outside of this cone is no illumination</td>
</tr>
<tr class="even">
<td align="left">float</td>
<td align="left">penumbraAngle</td>
<td align="left">size (angle in degree) of the &quot;penumbra&quot;, the region between the rim (of the illumination cone) and full intensity of the spot; should be smaller than half of <code>openingAngle</code></td>
</tr>
<tr class="odd">
<td align="left">float</td>
<td align="left">radius</td>
<td align="left">the size of the spot light, the radius of a disk with normal <code>direction</code></td>
</tr>
</tbody>
</table>

: Special parameters accepted by the spot light.

![Angles used by
SpotLight.](https://ospray.github.io/images/spot_light.png)

Setting the radius to a value greater than zero will result in soft
shadows when the renderer uses stochastic sampling (like the [path
tracer](#path-tracer)).

#### Quad Light

The quad[^3] light is a planar, procedural area light source emitting
uniformly on one side into the half space. It is created by passing the
type string "`quad`" to `ospNewLight`. In addition to the [general
parameters](#lights) understood by all lights the spot light supports
the following special parameters:

| Type     | Name     | Description                                          |
|:---------|:---------|:-----------------------------------------------------|
| vec3f(a) | position | world-space position of one vertex of the quad light |
| vec3f(a) | edge1    | vector to one adjacent vertex                        |
| vec3f(a) | edge2    | vector to the other adjacent vertex                  |

: Special parameters accepted by the quad light.

![Defining a Quad
Light.](https://ospray.github.io/images/quad_light.png)

The emission side is determined by the cross product of `edge1`×`edge2`.
Note that only renderers that use stochastic sampling (like the path
tracer) will compute soft shadows from the quad light. Other renderers
will just sample the `position` of the quad light, which results in hard
shadows.

#### HDRI Light

The HDRI light is a textured light source surrounding the scene and
illuminating it from infinity. It is created by passing the type string
"`hdri`" to `ospNewLight`. In addition to the [parameter
`intensity`](#lights) the HDRI light supports the following special
parameters:

<table style="width:97%;">
<caption>Special parameters accepted by the HDRI light.</caption>
<colgroup>
<col width="19%" />
<col width="9%" />
<col width="68%" />
</colgroup>
<thead>
<tr class="header">
<th align="left">Type</th>
<th align="left">Name</th>
<th align="left">Description</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td align="left">vec3f(a)</td>
<td align="left">up</td>
<td align="left">up direction of the light in world-space</td>
</tr>
<tr class="even">
<td align="left">vec3f(a)</td>
<td align="left">dir</td>
<td align="left">direction to which the center of the texture will be mapped to (analog to <a href="#panoramic-camera">panoramic camera</a>)</td>
</tr>
<tr class="odd">
<td align="left">OSPTexture2D</td>
<td align="left">map</td>
<td align="left">environment map in latitude / longitude format</td>
</tr>
</tbody>
</table>

: Special parameters accepted by the HDRI light.

![Orientation and Mapping of an HDRI
Light.](https://ospray.github.io/images/hdri_light.png)

Note that the currently only the [path tracer](#path-tracer) supports
the HDRI light.

#### Ambient Light

The ambient light surrounds the scene and illuminates it from infinity
with constant radiance (determined by combining the [parameters `color`
and `intensity`](#lights)). It is created by passing the type string
"`ambient`" to `ospNewLight`.

### Materials

Materials describe how light interacts with surfaces, they give objects
their distinctive look. To let the given renderer create a new material
of given type `type` call

``` {.cpp}
OSPMaterial ospNewMaterial(OSPRenderer, const char *type);
```

The call returns `NULL` if the material type is not known by the
renderer, or else an `OSPMaterial` handle to the created material. The
handle can then be used to assign the material to a given geometry with

``` {.cpp}
void ospSetMaterial(OSPGeometry, OSPMaterial);
```

#### OBJ Material

The OBJ material is the workhorse material supported by both the [SciVis
renderer](#scivis-renderer) and the [path tracer](#path-tracer). It
offers widely used common properties like diffuse and specular
reflection and is based on the [MTL material
format](http://paulbourke.net/dataformats/mtl/) of Lightwave's OBJ scene
files. To create an OBJ material pass the type string "`OBJMaterial`" to
`ospNewMaterial`. Its main parameters are

| Type         | Name      |    Default| Description                                        |
|:-------------|:----------|----------:|:---------------------------------------------------|
| vec3f        | Kd        |  white 0.8| diffuse color                                      |
| vec3f        | Ks        |      black| specular color                                     |
| float        | Ns        |         10| shininess (Phong exponent), usually in \[2–10^4^\] |
| float        | d         |     opaque| opacity                                            |
| vec3f        | Tf        |      black| transparency filter color                          |
| OSPTexture2D | map\_Bump |       NULL| normal map                                         |

: Main parameters of the OBJ material.

In particular when using the path tracer it is important to adhere to
the principle of energy conservation, i.e. that the amount of light
reflected by a surface is not larger than the light arriving. Therefore
the path tracer issues a warning and renormalizes the color parameters
if the sum of `Kd`, `Ks`, and `Tf` is larger than one in any color
channel. Similarly important to mention is that almost all materials of
the real world reflect at most only about 80% of the incoming light. So
even for a white sheet of paper or white wall paint do better not set
`Kd` larger than 0.8; otherwise rendering times are unnecessary long and
the contrast in the final images is low (for example, the corners of a
white room would hardly be discernible).

Note that currently only the path tracer implements colored transparency
with `Tf` and normal mapping to simulate small geometric features via
`map_Bump`. The normals $n$ in the normal map are wrt. the local
tangential shading coordinate system and are encoded as $½(n+1)$, thus a
texel $(0.5, 0.5, 1)$[^4] represents the unperturbed shading normal
$(0, 0, 1)$. Because of this encoding a linear [texture](#texture)
format is recommended for the normal map. Note that the orientation of
normal maps is important for a visually consistent look: by convention
OSPRay uses a coordinate system with the origin in the lower left
corner; thus a convexity will look green towards the top of the texture
image (see also the example image of a normal map). If this is not the
case flip the normal map vertically or invert its green channel.

<img src="https://ospray.github.io/images/normalmap_frustum.png" alt="Normal map representing an exalted square pyramidal frustum." style="width:60.0%" />

All parameters (except `Tf`) can be textured by passing a
[texture](#texture) handle, prefixed with "`map_`". The fetched texels
are multiplied by the respective parameter value. Texturing requires
[geometries](#geometries) with texture coordinates, e.g. a [triangle
mesh](#triangle-mesh) with `vertex.texcoord` provided. The color
textures `map_Kd` and `map_Ks` are typically in one of the sRGB gamma
encoded formats, whereas textures `map_Ns` and `map_d` are usually in a
linear format (and only the first component is used). The path tracer
additionally supports [texture
transformations](#texture-transformations) for all textures.

#### Glass

The [path tracer](#path-tracer) offers a realistic a glass material,
supporting refraction and volumetric attenuation (i.e. the transparency
color varies with the geometric thickness). To create a Glass material
pass the type string "`Glass`" to `ospNewMaterial`. Its parameters are

| Type  | Name                |  Default| Description                        |
|:------|:--------------------|--------:|:-----------------------------------|
| float | eta                 |      1.5| index of refraction                |
| vec3f | attenuationColor    |    white| resulting color due to attenuation |
| float | attenuationDistance |        1| distance affecting attenuation     |

: Parameters of the Glass material.

For convenience, the rather counterintuitive physical attenuation
coefficients will be calculated from the user inputs in such a way, that
the `attenuationColor` will be the result when white light traveled
trough a glass of thickness `attenuationDistance`.

### Texture

To create a new 2D texture of size `size` (in pixels) and with the given
format and flags use

``` {.cpp}
OSPTexture2D ospNewTexture2D(const vec2i &size,
                             const OSPTextureFormat,
                             void *source = NULL,
                             const uint32_t textureCreationFlags = 0);
```

The call returns `NULL` if the texture could not be created with the
given parameters, or else an `OSPTexture2D` handle to the created
texture. The supported texture formats are:

| Name                  | Description                                                 |
|:----------------------|:------------------------------------------------------------|
| OSP\_TEXTURE\_RGBA8   | 8 bit \[0–255\] linear components red, green, blue, alpha   |
| OSP\_TEXTURE\_SRGBA   | 8 bit sRGB gamma encoded color components, and linear alpha |
| OSP\_TEXTURE\_RGBA32F | 32 bit float components red, green, blue, alpha             |
| OSP\_TEXTURE\_RGB8    | 8 bit \[0–255\] linear components red, green, blue          |
| OSP\_TEXTURE\_SRGB    | 8 bit sRGB gamma encoded components red, green, blue        |
| OSP\_TEXTURE\_RGB32F  | 32 bit float components red, green, blue                    |
| OSP\_TEXTURE\_R8      | 8 bit \[0–255\] linear single component                     |
| OSP\_TEXTURE\_R32F    | 32 bit float single component                               |

: Supported texture formats by `ospNewTexture2D`, i.e. valid constants
of type `OSPTextureFormat`.

The texel data addressed by `source` starts with the texels in the lower
left corner of the texture image, like in OpenGL. Similar to
[data](#data) buffers the texel data can be shared by the application by
specifying the `OSP_TEXTURE_SHARED_BUFFER` flag. Per default a texture
fetch is filtered by performing bi-linear interpolation of the nearest
2×2 texels; if instead fetching only the nearest texel is desired (i.e.
no filtering) then pass the `OSP_TEXTURE_FILTER_NEAREST` flag. Both
texture creating flags can be combined with a bitwise OR.

### Texture Transformations

Many materials with textures also offer to manipulate the placement of
these textures with the help of texture transformations. If so, this
convention shall be used. The following parameters (prefixed with
"`texture_name.`") are combined into one transformation matrix:

| Type  | Name        | Description                                           |
|:------|:------------|:------------------------------------------------------|
| vec4f | transform   | interpreted as 2×2 matrix (linear part), column-major |
| float | rotation    | angle in degree, counterclock-wise, around center     |
| vec2f | scale       | enlarge texture, relative to center (0.5, 0.5)        |
| vec2f | translation | move texture in positive direction (right/up)         |

: Parameters to define texture coordinate transformations.

The transformations are applied in the given order. Rotation, scale and
translation are interpreted "texture centric", i.e. their effect seen by
an user are relative to the texture (although the transformations are
applied to the texture coordinates).

### Cameras

To create a new camera of given type `type` use

``` {.cpp}
OSPCamera ospNewCamera(const char *type);
```

The call returns `NULL` if that type of camera is not known, or else an
`OSPCamera` handle to the created camera. All cameras accept these
parameters:

| Type     | Name       | Description                               |
|:---------|:-----------|:------------------------------------------|
| vec3f(a) | pos        | position of the camera in world-space     |
| vec3f(a) | dir        | main viewing direction of the camera      |
| vec3f(a) | up         | up direction of the camera                |
| float    | nearClip   | near clipping distance                    |
| vec2f    | imageStart | start of image region (lower left corner) |
| vec2f    | imageEnd   | end of image region (upper right corner)  |

: Parameters accepted by all cameras.

The camera is placed and oriented in the world with `pos`, `dir` and
`up`. The region of the camera sensor that is rendered to the image can
be specified in normalized screen-space coordinates with `imageStart`
(lower left corner) and `imageEnd` (upper right corner). This can be
used, for example, to crop the image or to achieve asymmetrical view
frusta. Note that values outside the default range of \[0–1\] are valid,
which is useful to easily realize overscan or film gate, or to emulate a
shifted sensor.

#### Perspective Camera

The perspective camera implements a simple thinlens camera for
perspective rendering, supporting optionally depth of field and stereo
rendering, but no motion blur. It is created by passing the type string
"`perspective`" to `ospNewCamera`. In addition to the [general
parameters](#cameras) understood by all cameras the perspective camera
supports the special parameters listed in the table below.

<table style="width:97%;">
<caption>Parameters accepted by the perspective camera.</caption>
<colgroup>
<col width="9%" />
<col width="32%" />
<col width="55%" />
</colgroup>
<thead>
<tr class="header">
<th align="left">Type</th>
<th align="left">Name</th>
<th align="left">Description</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td align="left">float</td>
<td align="left">fovy</td>
<td align="left">the field of view (angle in degree) of the frame's height</td>
</tr>
<tr class="even">
<td align="left">float</td>
<td align="left">aspect</td>
<td align="left">ratio of width by height of the frame</td>
</tr>
<tr class="odd">
<td align="left">float</td>
<td align="left">apertureRadius</td>
<td align="left">size of the aperture, controls the depth of field</td>
</tr>
<tr class="even">
<td align="left">float</td>
<td align="left">focusDistance</td>
<td align="left">distance at where the image is sharpest when depth of field is enabled</td>
</tr>
<tr class="odd">
<td align="left">bool</td>
<td align="left">architectural</td>
<td align="left">vertical edges are projected to be parallel</td>
</tr>
<tr class="even">
<td align="left">int</td>
<td align="left">stereoMode</td>
<td align="left">0: no stereo (default), 1: left eye, 2: right eye, 3: side-by-side</td>
</tr>
<tr class="odd">
<td align="left">float</td>
<td align="left">interpupillaryDistance</td>
<td align="left">distance between left and right eye when stereo is enabled</td>
</tr>
</tbody>
</table>

: Parameters accepted by the perspective camera.

Note that when setting the `aspect` ratio a non-default image region
(using `imageStart` & `imageEnd`) needs to be regarded.

In architectural photography it is often desired for aesthetic reasons
to display the vertical edges of buildings or walls vertically in the
image as well, regardless of how the camera is tilted. Enabling the
`architectural` mode achieves this by internally leveling the camera
parallel to the ground (based on the `up` direction) and then shifting
the lens such that the objects in direction `dir` are centered in the
image. If finer control of the lens shift is needed use `imageStart` &
`imageEnd`. Because the camera is now effectively leveled its image
plane and thus the plane of focus is oriented parallel to the front of
buildings, the whole façade appears sharp, as can be seen in the example
images below.

<img src="https://ospray.github.io/images/camera_perspective.jpg" alt="Example image created with the perspective camera, featuring depth of field." style="width:60.0%" />

<img src="https://ospray.github.io/images/camera_architectual.jpg" alt="Enabling the architectural flag corrects the perspective projection distortion, resulting in parallel vertical edges." style="width:60.0%" />

<img src="https://ospray.github.io/images/camera_stereo.jpg" alt="Example 3D stereo image using stereoMode side-by-side." style="width:90.0%" />

#### Orthographic Camera

The orthographic camera implements a simple camera with orthographic
projection, without support for depth of field or motion blur. It is
created by passing the type string "`orthographic`" to `ospNewCamera`.
In addition to the [general parameters](#cameras) understood by all
cameras the orthographic camera supports the following special
parameters:

| Type  | Name   | Description                                                 |
|:------|:-------|:------------------------------------------------------------|
| float | height | size of the camera's image plane in y, in world coordinates |
| float | aspect | ratio of width by height of the frame                       |

: Parameters accepted by the orthographic camera.

For convenience the size of the camera sensor, and thus the extent of
the scene that is captured in the image, can be controlled with the
`height` parameter. The same effect can be achieved with `imageStart`
and `imageEnd`, and both methods can be combined. In any case, the
`aspect` ratio needs to be set accordingly to get an undistorted image.

<img src="https://ospray.github.io/images/camera_orthographic.jpg" alt="Example image created with the orthographic camera." style="width:60.0%" />

#### Panoramic Camera

The panoramic camera implements a simple camera without support for
motion blur. It captures the complete surrounding with a latitude /
longitude mapping and thus the rendered images should best have a ratio
of 2:1. A panoramic camera is created by passing the type string
"`panoramic`" to `ospNewCamera`. It is placed and oriented in the scene
by using the [general parameters](#cameras) understood by all cameras.

<img src="https://ospray.github.io/images/camera_panoramic.jpg" alt="Latitude / longitude map created with the panoramic camera." style="width:90.0%" />

### Picking

To get the world-space position of the geometry (if any) seen at \[0–1\]
normalized screen-space pixel coordinates `screenPos` use

``` {.cpp}
void ospPick(OSPPickResult*, OSPRenderer, const vec2f &screenPos);
```

The result is returned in the provided `OSPPickResult` struct:

``` {.cpp}
typedef struct {
    vec3f position; // the position of the hit point (in world-space)
    bool hit;       // whether or not a hit actually occurred
} OSPPickResult;
```

Note that `ospPick` considers exactly the same camera of the given
renderer that is used to render an image, thus matching results can be
expected. If the camera supports depth of field then the center of the
lens and thus the center of the circle of confusion is used for picking.

Framebuffer
-----------

The framebuffer holds the rendered 2D image (and optionally auxiliary
information associated with pixels). To create a new framebuffer object
of given size `size` (in pixels), color format, and channels use

``` {.cpp}
OSPFrameBuffer ospNewFrameBuffer(const vec2i &size,
                                 const OSPFrameBufferFormat format = OSP_FB_SRGBA,
                                 const uint32_t frameBufferChannels = OSP_FB_COLOR);
```

The parameter `format` describes the format the color buffer has *on the
host*, and the format that `ospMapFrameBuffer` will eventually return.
Valid values are:

| Name             | Description                                                 |
|:-----------------|:------------------------------------------------------------|
| OSP\_FB\_NONE    | framebuffer will not be mapped by the application           |
| OSP\_FB\_RGBA8   | 8 bit \[0–255\] linear component red, green, blue, alpha    |
| OSP\_FB\_SRGBA   | 8 bit sRGB gamma encoded color components, and linear alpha |
| OSP\_FB\_RGBA32F | 32 bit float components red, green, blue, alpha             |

: Supported color formats of the framebuffer that can be passed to
`ospNewFrameBuffer`, i.e. valid constants of type
`OSPFrameBufferFormat`.

The parameter `frameBufferChannels` specifies which channels the
framebuffer holds, and can be combined together by bitwise OR from the
values of `OSPFrameBufferChannel` listed in the table below.

| Name              | Description                                                   |
|:------------------|:--------------------------------------------------------------|
| OSP\_FB\_COLOR    | RGB color including alpha                                     |
| OSP\_FB\_DEPTH    | Euclidean distance to the camera (*not* to the image plane)   |
| OSP\_FB\_ACCUM    | accumulation buffer for progressive refinement                |
| OSP\_FB\_VARIANCE | estimate of the current variance, see [rendering](#rendering) |

: Framebuffer channels constants (of type `OSPFrameBufferChannel`),
naming optional information the framebuffer can store. These values can
be combined by bitwise OR when passed to `ospNewFrameBuffer` or
`ospClearFrameBuffer`.

If a certain channel value is *not* specified, the given buffer channel
will not be present. Note that ospray makes a very clear distinction
between the *external* format of the framebuffer and the internal one:
The external format is the format the user specifies in the `format`
parameter; it specifies what color format OSPRay will eventually
*return* the framebuffer to the application (when calling
`ospMapFrameBuffer`): no matter what OSPRay uses internally, it will
simply return a 2D array of pixels of that format, with possibly all
kinds of reformatting, compression/decompression, etc, going on
in-between the generation of the *internal* framebuffer and the mapping
of the externally visible one.

In particular, `OSP_FB_NONE` is a perfectly valid pixel format for a
framebuffer that an application will never map. For example, an
application driving a display wall may well generate an intermediate
framebuffer and eventually transfer its pixel to the individual displays
using an `OSPPixelOp` [pixel operation](#pixel-operation).

A framebuffer can be freed again using

``` {.cpp}
void ospFreeFrameBuffer(OSPFrameBuffer);
```

Because OSPRay uses reference counting internally the framebuffer may
not immediately be deleted at this time.

The application can map the given channel of a framebuffer -- and thus
access the stored pixel information -- via

``` {.cpp}
const void *ospMapFrameBuffer(OSPFrameBuffer,
                              const OSPFrameBufferChannel = OSP_FB_COLOR);
```

Note that only `OSP_FB_COLOR` or `OSP_FB_DEPTH` can be mapped. The
origin of the screen coordinate system in OSPRay is the lower left
corner (as in OpenGL), thus the first pixel addressed by the returned
pointer is the lower left pixel of the image.

A previously mapped channel of a framebuffer can be unmapped by passing
the received pointer `mapped` to

``` {.cpp}
void ospUnmapFrameBuffer(const void *mapped, OSPFrameBuffer);
```

The individual channels of a framebuffer can be cleared with

``` {.cpp}
void ospFrameBufferClear(OSPFrameBuffer, const uint32_t frameBufferChannels);
```

When selected, `OSP_FB_COLOR` will clear the color buffer to black
`(0, 0, 0, 0)`, `OSP_FB_DEPTH` will clear the depth buffer to `inf`,
`OSP_FB_ACCUM` will clear the accumulation buffer to black, resets the
accumulation counter `accumID` and also clears the variance buffer (if
present) to `inf`.

### Pixel Operation {#pixel-operation .unnumbered}

A pixel operation are functions that are applied to every pixel that
gets written into a framebuffer. Examples include post-processing,
filtering, blending, tone mapping, or sending tiles to a display wall.
To create a new pixel operation of given type `type` use

``` {.cpp}
OSPPixelOp ospNewPixelOp(const char *type);
```

The call returns `NULL` if that type is not known, or else an
`OSPPixelOp` handle to the created pixel operation.

To set a pixel operation to the given framebuffer use

``` {.cpp}
void ospSetPixelOp(OSPFrameBuffer, OSPPixelOp);
```

Rendering
---------

To render a frame into the given framebuffer with the given renderer use

``` {.cpp}
float ospRenderFrame(OSPFrameBuffer, OSPRenderer,
                     const uint32_t frameBufferChannels = OSP_FB_COLOR);
```

The third parameter specifies what channel(s) of the framebuffer is
written to[^5]. What to render and how to render it depends on the
renderer's parameters. If the framebuffer supports accumulation (i.e. it
was created with `OSP_FB_ACCUM`) then successive calls to
`ospRenderFrame` will progressively refine the rendered image. If
additionally the framebuffer has an `OSP_FB_VARIANCE` channel then
`ospRenderFrame` returns an estimate of the current variance of the
rendered image, otherwise `inf` is returned. The estimated variance can
be used by the application as a quality indicator and thus to decide
whether to stop or to continue progressive rendering.

Examples
========

Tutorial
--------

A minimal working example demonstrating how to use OSPRay can be found
at `apps/ospTutorial.cpp`[^6]. On Linux build it in the build\_directory
with

    g++ ../apps/ospTutorial.cpp -I ../ospray/include -I .. -I ../ospray/embree/common \
      ./libospray.so -Wl,-rpath,. -o ospTutorial

On Windows build it in the build\_directory\\\$Configuration with

    cl ..\..\apps\ospTutorial.cpp /EHsc -I ..\..\ospray\include -I ..\..  ^
      -I ..\..\ospray\embree\common ospray.lib

Running `ospTutorial` will create two images of two triangles, rendered
with the Scientific Visualization renderer with full Ambient Occlusion.
The first image `firstFrame.ppm` shows the result after one call to
`ospRenderFrame` -- jagged edges and noise in the shadow can be seen.
Calling `ospRenderFrame` multiple times enables progressive refinement,
resulting in antialiased edges and converged shadows, shown after ten
frames in the second image `accumulatedFrames.png`.

![First frame.](https://ospray.github.io/images/tutorial_firstframe.png)

![After accumulating ten
frames.](https://ospray.github.io/images/tutorial_accumulatedframe.png)

Qt Viewer
---------

OSPRay also includes a demo viewer application `ospQtViewer`, showcasing
all features of OSPRay.

![Screenshot of
`ospQtViewer`.](https://ospray.github.io/images/QtViewer.jpg)

Volume Viewer
-------------

Additionally, OSPRay includes a demo viewer application
`ospVolumeViewer`, which is specifically tailored for volume rendering.

![Screenshot of
`ospVolumeViewer`.](https://ospray.github.io/images/VolumeViewer.png)

Demos
-----

Several ready-to-run demos, models and data sets for OSPRay can be found
at the [OSPRay Demos and Examples](http://www.ospray.org/demos.html)
page.

[^1]: For example, if OSPRay is in `~/Projects/ospray`, ISPC will also
    be searched in `~/Projects/ispc-v1.9.1-linux` and
    `~/Projects/ispc-v1.9.0-linux`

[^2]: The [HDRI Light](#hdri-light) is an exception, it knows about
    `intensity`, but not about `color`.

[^3]: actually a parallelogram

[^4]: respectively $(127, 127, 255)$ for 8 bit textures

[^5]: This is currently not implemented, i.e. all channels of the
    framebuffer are always updated.

[^6]: A C99 version is available at `apps/ospTutorial.c`.
