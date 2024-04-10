#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Draw.h"
#include "setting.h"
#include "ObjectsRain.h"
#include "MenuItem.h"

void start();
void quit();
void openSetting();
void onFocusSlider(sf::Sprite* aSprite);
void outFocusSlider(sf::Sprite* aSprite);
void onChangeVolumeSlider(float value);
void onChangePitchSlider(float value);
void updateMenuItems(MenuItem* menuObjects[], int size, sf::RenderWindow *window) {
    for (int i = 0; i < size; i++) {
        menuObjects[i]->update(window);
    }
}

void onFocusMenuButton(sf::Sprite* aSprite, sf::Text* aText);
void outFocusMenuButton(sf::Sprite* aSprite, sf::Text* aText);

instruments::window s_window = instruments::window::menu;

sf::RenderWindow window(sf::VideoMode(setting::WIDTH, setting::HEIGHT), "Catch them!");

// loading
sf::Texture playerTexture;
sf::Texture textureObject1;
sf::Texture backgroundTexture;
sf::Texture buttonBackgroundTexture;
sf::Texture buttonBackgroundTextureOnFocus;
sf::Texture thumbBackgroundTexture;
sf::Texture sliderBackgroundTexture;

sf::Image icon;
sf::Image defaultCursorImage;
sf::Image handCursorImage;

sf::Font fontButtons;

sf::Cursor	defaultCursor;
sf::Cursor	handCursor;

sf::Music backMusic;
sf::SoundBuffer pick;

Player player;

int numInFocusItems = 0;

float volume = 50;
float pitch = 1;

int main()
{
    icon.loadFromFile("res/textures/icon.png");
    defaultCursorImage.loadFromFile("res/textures/cursor.png");
    handCursorImage.loadFromFile("res/textures/handCursor.png");


    playerTexture.loadFromFile("res/textures/box.png");
    textureObject1.loadFromFile("res/textures/sweet.png");
    backgroundTexture.loadFromFile("res/textures/background.png");
    buttonBackgroundTexture.loadFromFile("res/textures/buttonBackground.png");
    buttonBackgroundTextureOnFocus.loadFromFile("res/textures/buttonBackgroundOnFocus.png");
    thumbBackgroundTexture.loadFromFile("res/textures/thumbBackground.png");
    sliderBackgroundTexture.loadFromFile("res/textures/sliderBackground.png");


    fontButtons.loadFromFile("res/fonts/MarckScript-Regular.ttf");

    sf::Text buttonText;

    buttonText.setFillColor(sf::Color(34, 111, 84));
    buttonText.setFont(fontButtons);
    buttonText.setCharacterSize(50);

    defaultCursor.loadFromPixels(defaultCursorImage.getPixelsPtr(), defaultCursorImage.getSize(), { 0, 0 });
    handCursor.loadFromPixels(handCursorImage.getPixelsPtr(), handCursorImage.getSize(), { 0, 0 });

    sf::Sprite playerSprite(playerTexture);

    sf::Sprite spriteObject1(textureObject1);

    buttonText.setString("Start");
    Button button1(&buttonBackgroundTexture, buttonText, instruments::Pos(52, 39), instruments::Pos(262, 65));
    buttonText.setString("Options");
    Button button2(&buttonBackgroundTexture, buttonText, instruments::Pos(52, 183), instruments::Pos(221, 209));
    buttonText.setString("Quit");
    Button button3(&buttonBackgroundTexture, buttonText, instruments::Pos(52, 327), instruments::Pos(273, 353));
    button1.setOnClickFunction(start);
    button2.setOnClickFunction(openSetting);
    button3.setOnClickFunction(quit);
    button1.setOnFocusFunction(onFocusMenuButton);
    button2.setOnFocusFunction(onFocusMenuButton);
    button3.setOnFocusFunction(onFocusMenuButton);
    button1.setOutFocusFunction(outFocusMenuButton);
    button2.setOutFocusFunction(outFocusMenuButton);
    button3.setOutFocusFunction(outFocusMenuButton);

    Slider sliderVolume(&sliderBackgroundTexture, &thumbBackgroundTexture, instruments::Pos(72, 130), instruments::Pos(0, 100), volume);
    Slider sliderPitch(&sliderBackgroundTexture, &thumbBackgroundTexture, instruments::Pos(72, 365), instruments::Pos(0, 5), pitch);

    sliderVolume.setOnFocusFunction(onFocusSlider);
    sliderVolume.setOutFocusFunction(outFocusSlider);
    sliderVolume.setOnChangeFunction(onChangeVolumeSlider);
    sliderPitch.setOnFocusFunction(onFocusSlider);
    sliderPitch.setOutFocusFunction(outFocusSlider);
    sliderPitch.setOnChangeFunction(onChangePitchSlider);

    backMusic.openFromFile("res/sounds/backMusic.mp3");
    pick.loadFromFile("res/sounds/pick.wav");

    backMusic.setLoop(true);
    backMusic.play();

    player = Player(setting::FIRST_PLAYER_POS, playerSprite);
    Draw draw;
    ObjectsRain OR({spriteObject1});

    MenuItem* menuItems[] = { &button1, &button2, &button3 };
    MenuItem* settingItems[] = { &sliderVolume, &sliderPitch };


    window.setIcon(128, 128, icon.getPixelsPtr());

    sf::Clock startFrame;
    float wasTime;

    OR.setSoundBuffer(pick);

    while (window.isOpen())
    {
        if (window.hasFocus()) {
            numInFocusItems = 0;
            wasTime = startFrame.getElapsedTime().asMicroseconds();
            setting::SPEED_FALLING += wasTime * 0.001 * 0.0001;
            setting::SPEED_PLAYER += wasTime * 0.0005 * 0.0001;
            startFrame.restart();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyReleased
                    && event.key.scancode == sf::Keyboard::Scan::Escape) {
                    switch (s_window)
                    {
                    case instruments::window::game:
                        s_window = instruments::window::menu;
                        break;
                    case instruments::window::menu:
                        s_window = instruments::window::game;
                        break;
                    case instruments::window::settings:
                        s_window = instruments::window::menu;
                        break;
                    default:
                        break;
                    }
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            }

            player.move(wasTime);
            OR.update(&player, wasTime, s_window);
            window.clear();

            draw.drawBackground(backgroundTexture, &window);
            draw.drawObjects(OR.getObjects(), &window);
            if (s_window == instruments::window::menu) {
                draw.drawMenu(menuItems, 3, &window);
                updateMenuItems(menuItems, 3, &window);
                if (numInFocusItems == 0)
                    window.setMouseCursor(defaultCursor);
            }
            else if (s_window == instruments::window::settings) {
                draw.drawMenu(settingItems, 2, &window);
                sf::Text volumeText("volume: " + std::to_string((int)(volume)) + "%", fontButtons, 50);
                volumeText.setPosition(210, 40);
                window.draw(volumeText);
                sf::Text pitchText("pitch: " + std::to_string(pitch), fontButtons, 50);
                pitchText.setPosition(210, 280);
                window.draw(pitchText);
                updateMenuItems(settingItems, 2, &window);
                if (numInFocusItems == 0)
                    window.setMouseCursor(defaultCursor);
            }
            else {
                window.setMouseCursor(defaultCursor);
                draw.drawPlayer(player, &window);

                setting::SPEED_FALLING += 0.01;
                setting::SPEED_PLAYER += 0.7;
            }
            window.display();
        }
    }

    return 0;
}

void start() {
    s_window = instruments::window::game;
}

void openSetting() {
    s_window = instruments::window::settings;
}

void quit() {
    window.close();
}

void onFocusMenuButton(sf::Sprite* aSprite, sf::Text* aText) {
    aSprite->setTexture(buttonBackgroundTextureOnFocus);
    aText->setOutlineThickness(2);
    aText->setOutlineColor(sf::Color(244, 240, 187));
    numInFocusItems += 1;
    window.setMouseCursor(handCursor);
}

void onFocusSlider(sf::Sprite* aSprite) {
    window.setMouseCursor(handCursor);
    numInFocusItems += 1;
}

void outFocusSlider(sf::Sprite* aSprite) {

}

void onChangeVolumeSlider(float value) {
    volume = value;
    sf::Listener::setGlobalVolume(volume);
}
void onChangePitchSlider(float value) {
    pitch = value;
    backMusic.setPitch(pitch);
}

void outFocusMenuButton(sf::Sprite* aSprite, sf::Text* aText) {
    aSprite->setTexture(buttonBackgroundTexture);
    aText->setOutlineThickness(0);
}