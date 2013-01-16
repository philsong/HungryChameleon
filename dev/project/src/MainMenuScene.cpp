#include "pch.h"
#include "MainMenuScene.h"
#include "VisibleRect.h"

MainMenu::MainMenu()
{
    m_pMainMenu = CCMenu::create();

    CCLabelTTF* label = CCLabelTTF::create("Start Game", "Arial", 24);
    m_pStartButton = CCMenuItemLabel::create(label);
    m_pStartButton->setPosition( ccp( VisibleRect::center().x, VisibleRect::center().y) );

    //m_pMainMenu->setContentSize(CCSizeMake(VisibleRect::getVisibleRect().size.width, (4 + 1) * 40));
    m_pMainMenu->setPosition(0.f, 0.f);
    m_pMainMenu->addChild(m_pStartButton);

    addChild(m_pMainMenu);

    setTouchEnabled(true);
}

CCMenuItemLabel* MainMenu::getStartButton() const
{
    return m_pStartButton;
}

MainMenu::~MainMenu()
{
}

//------------------------------------------------------------------//
MainMenuScene::MainMenuScene(): m_pMainMenu(nullptr)
{

}

MainMenuScene::~MainMenuScene()
{
    
}

void MainMenuScene::onEnter()
{
    GameScene::onEnter();

}

bool MainMenuScene::init()
{
    if (GameScene::init())
    {
        CCLayerColor* pBackground = CCLayerColor::create();
        pBackground->initWithColor(ccc4(0, 166, 0, 255));

        m_pMainMenu = new MainMenu();
        m_pMainMenu->getStartButton()->setTarget(this, menu_selector(MainMenuScene::startCallback));

        addChild(pBackground);
        addChild(m_pMainMenu);
        m_pMainMenu->release();
    
        CCDirector::sharedDirector()->runWithScene(this);
        return true;
    }

    return false;
}

void MainMenuScene::startCallback(CCObject * pSender)
{

}