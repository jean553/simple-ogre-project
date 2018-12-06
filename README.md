# simple-ogre-project

A very simple application with Ogre3D displaying a Blender made mesh.

## Required tools

The model of this project has been made with Blender
and exported using the **OGRE Exporter** Blender plugin.

## Build

```sh
cd build/
cmake .. && make
```

## Set resources path

`resources.cfg` is automatically generated during `cmake` execution,
the following content is enough though:

```
[General]
FileSystem=../models
```

## Run

```sh
./ogre-test
```
