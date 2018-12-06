#include "Ogre.h"
#include "OgreApplicationContext.h"

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
        Ogre::SceneManager* scnMgr = root->createSceneManager();

        Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
        shadergen->addSceneManager(scnMgr);

        Ogre::Light* light = scnMgr->createLight("MainLight");
        Ogre::SceneNode* lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
        lightNode->setPosition(8, -9, 13);
        lightNode->attachObject(light);

        Ogre::SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
        camNode->setPosition(21, -20, 20);
        camNode->setOrientation(Ogre::Quaternion(Ogre::Degree(63),Ogre::Vector3(1,0,0)));
        camNode->setOrientation(Ogre::Quaternion(Ogre::Degree(0),Ogre::Vector3(0,1,0)));
        camNode->setOrientation(Ogre::Quaternion(Ogre::Degree(46),Ogre::Vector3(0,0,1)));
        camNode->lookAt(Ogre::Vector3(0, 0, 5), Ogre::Node::TS_PARENT);

        Ogre::Camera* cam = scnMgr->createCamera("myCam");
        cam->setNearClipDistance(1); 
        cam->setAutoAspectRatio(true);
        camNode->attachObject(cam);

        getRenderWindow()->addViewport(cam);

        Ogre::Entity* ent = scnMgr->createEntity("Circle.mesh");
        Ogre::SceneNode* node = scnMgr->getRootSceneNode()->createChildSceneNode();
        node->scale(Ogre::Vector3(0.15f, 0.15f, 0.15f));
        node->setPosition(0, 0, 5);
        node->attachObject(ent);
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
