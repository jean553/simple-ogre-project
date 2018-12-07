#include "Ogre.h"
#include "OgreApplicationContext.h"

#include <iostream>
#include <memory>

class App : public OgreBites::ApplicationContext, public OgreBites::InputListener
{
    /**
     * Initializes the scene.
     */
    void setup()
    {
        OgreBites::ApplicationContext::setup();
        addInputListener(this);

        Ogre::Root* root = getRoot();
        Ogre::SceneManager* const sceneManager = root->createSceneManager();

        Ogre::RTShader::ShaderGenerator* const shaderGenerator =
            Ogre::RTShader::ShaderGenerator::getSingletonPtr();
        shaderGenerator->addSceneManager(sceneManager);

        Ogre::Light* const light = sceneManager->createLight("light");

        Ogre::Camera* const camera = sceneManager->createCamera("camera");
        camera->setNearClipDistance(1); 
        camera->setAutoAspectRatio(true);

        Ogre::Entity* const lamp = sceneManager->createEntity("Circle.mesh");

        constexpr Ogre::Real LIGHT_POSITION_X {8};
        constexpr Ogre::Real LIGHT_POSITION_Y {-9};
        constexpr Ogre::Real LIGHT_POSITION_Z {13};

        Ogre::SceneNode* const lightNode = sceneManager->getRootSceneNode()->createChildSceneNode();
        lightNode->setPosition(
            LIGHT_POSITION_X,
            LIGHT_POSITION_Y,
            LIGHT_POSITION_Z
        );
        lightNode->attachObject(light);

        constexpr Ogre::Real CAMERA_POSITION_X {21};
        constexpr Ogre::Real CAMERA_POSITION_Y {-20};
        constexpr Ogre::Real CAMERA_POSITION_Z {20};

        constexpr Ogre::Real CAMERA_ROTATION_X {63};
        constexpr Ogre::Real CAMERA_ROTATION_Y {0};
        constexpr Ogre::Real CAMERA_ROTATION_Z {46};

        constexpr Ogre::Real CAMERA_LOOK_AT_X {0};
        constexpr Ogre::Real CAMERA_LOOK_AT_Y {0};
        constexpr Ogre::Real CAMERA_LOOK_AT_Z {5};

        Ogre::SceneNode* const cameraNode = sceneManager->getRootSceneNode()->createChildSceneNode();
        cameraNode->setPosition(
            CAMERA_POSITION_X,
            CAMERA_POSITION_Y,
            CAMERA_POSITION_Z
        );

        cameraNode->setOrientation(
            Ogre::Quaternion(
                Ogre::Degree(CAMERA_ROTATION_X),
                Ogre::Vector3(1,0,0)
            )
        );
        cameraNode->setOrientation(
            Ogre::Quaternion(
                Ogre::Degree(CAMERA_ROTATION_Y),
                Ogre::Vector3(0,1,0)
            )
        );
        cameraNode->setOrientation(
            Ogre::Quaternion(
                Ogre::Degree(CAMERA_ROTATION_Z),
                Ogre::Vector3(0,0,1)
            )
        );

        cameraNode->lookAt(
            Ogre::Vector3(
                CAMERA_LOOK_AT_X,
                CAMERA_LOOK_AT_Y,
                CAMERA_LOOK_AT_Z
            ),
            Ogre::Node::TS_PARENT
        );

        cameraNode->attachObject(camera);

        constexpr Ogre::Real LAMP_POSITION_X {0};
        constexpr Ogre::Real LAMP_POSITION_Y {0};
        constexpr Ogre::Real LAMP_POSITION_Z {5};

        constexpr Ogre::Real LAMP_SCALE_X {0.15};
        constexpr Ogre::Real LAMP_SCALE_Y {0.15};
        constexpr Ogre::Real LAMP_SCALE_Z {0.15};

        Ogre::SceneNode* const lampNode = sceneManager->getRootSceneNode()->createChildSceneNode();
        lampNode->scale(
            Ogre::Vector3(
                LAMP_SCALE_X,
                LAMP_SCALE_Y,
                LAMP_SCALE_Z
            )
        );
        lampNode->setPosition(
            LAMP_POSITION_X,
            LAMP_POSITION_Y,
            LAMP_POSITION_Z
        );
        lampNode->attachObject(lamp);

        getRenderWindow()->addViewport(camera);
    }
};

/**
 *
 */
int main(int argc, char *argv[])
{
    App app;
    app.initApp();
    app.getRoot()->startRendering();
    app.closeApp();

    return EXIT_SUCCESS;
}
