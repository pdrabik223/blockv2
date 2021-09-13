//
// Created by studio25 on 19.08.2021.
//

#include "creator_input_panel.h"
#include <toggle_text_button.h>

sfml_window::CreatorInputPanel::CreatorInputPanel(unsigned int window_width,
                                                  unsigned int window_height,
                                                  const LevelInfo &target)
    : window_width_(window_width), window_height_(window_height),
      target_(target) {
  LoadCreatorInputPanelTexts();
  LoadButtons();
  LoadBackground();
  LoadLabels();
}
sfml_window::CreatorInputPanel::CreatorInputPanel(
    const CreatorInputPanel &other)
    : target_(other.target_) {
  window_width_ = other.window_width_;
  window_height_ = other.window_height_;
  background_texture_ = other.background_texture_;
  background_sprite_ = other.background_sprite_;
  button_background_ = other.button_background_;

  for (int i = 0; i < other.buttons_.size(); i++)
    buttons_[i] = other.buttons_[i]->Clone();

  in_focus_ = other.in_focus_;

  for (int i = 0; i < other.input_panels_.size(); i++)
    input_panels_[i] = other.input_panels_[i];

  for (int i = 0; i < other.input_panels_labels_.size(); i++)
    input_panels_labels_[i] = other.input_panels_labels_[i];
}

void sfml_window::CreatorInputPanel::DrawToWindow(sf::RenderWindow &window) {
  window.draw(background_sprite_);

  for (const auto &button : buttons_)
    button->DrawToWindow(window);

  ClearHighlight();

  for (ToggleTextButton &i : input_panels_)
    i.DrawToWindow(window);

  for (auto &i : input_panels_labels_)
    i.DrawToWindow(window);
}

bool sfml_window::CreatorInputPanel::HandleLetter(const sf::Event &event) {
  if (in_focus_ != CreatorInputPanelTextField::WIDTH and
      in_focus_ != CreatorInputPanelTextField::HEIGHT)

    if (event.key.code >= sf::Keyboard::A and
        event.key.code <= sf::Keyboard::Z) {
      std::string text = input_panels_[(int)in_focus_].GetText();
      if (text.size() == 30)
        return false;

      char letter = event.key.code;

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) or
          sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
        letter += 'A';
      else
        letter += 'a';

      text += letter;
      input_panels_[(int)in_focus_].SetText(text);
      return true;
    } else if (event.key.code == sf::Keyboard::Space) {
      std::string text = input_panels_[(int)in_focus_].GetText();
      if (text.size() == 30)
        return false;
      text += '_';
      input_panels_[(int)in_focus_].SetText(text);
      return true;
    } else if (event.key.code >= sf::Keyboard::Num0 and
               event.key.code <= sf::Keyboard::Num9) {

      std::string text = input_panels_[(int)in_focus_].GetText();
      if (text.size() == 30)
        return false;
      char letter = '0' + event.key.code - sf::Keyboard::Num0;
      text += letter;
      input_panels_[(int)in_focus_].SetText(text);

      return true;
    }

  return false;
}
bool sfml_window::CreatorInputPanel::HandleNumber(const sf::Event &event) {

  if (in_focus_ == CreatorInputPanelTextField::WIDTH or
      in_focus_ == CreatorInputPanelTextField::HEIGHT)
    if (event.key.code >= sf::Keyboard::Num0 and
        event.key.code <= sf::Keyboard::Num9) {

      std::string text = input_panels_[(int)in_focus_].GetText();
      char letter = '0' + event.key.code - sf::Keyboard::Num0;
      text += letter;
      input_panels_[(int)in_focus_].SetText(text);

      return true;
    }
  return false;
}
bool sfml_window::CreatorInputPanel::HandleFunctional(const sf::Event &event) {
  if (event.key.code == sf::Keyboard::Backspace) {
    std::string text = input_panels_[(int)in_focus_].GetText();
    if (text.size() > 0)
      text.erase(text.size() - 1);
    input_panels_[(int)in_focus_].SetText(text);
    return true;
  }
  return false;
}

sfml_window::ContextEvent
sfml_window::CreatorInputPanel::HandleEvent(sf::Event &event,
                                            const sf::RenderWindow &window) {
  int mouse_x = sf::Mouse::getPosition(window).x;
  int mouse_y = sf::Mouse::getPosition(window).y;

  mouse_x = mouse_x < 0 ? 0 : mouse_x;
  mouse_y = mouse_y < 0 ? 0 : mouse_y;

  mouse_x = mouse_x <= window_width_ ? mouse_x : window_width_ - 1;
  mouse_y = mouse_y <= window_height_ ? mouse_y : window_height_ - 1;

  bool change = false; // if true window should be re-loaded to display change
  // in appearance

  if (event.type == sf::Event::KeyPressed)
    if (in_focus_ != CreatorInputPanelTextField::SIZE) {

      if (event.key.code == sf::Keyboard::Enter) {
        in_focus_ = CreatorInputPanelTextField::SIZE;
        return ContextEvent::UPDATE_DISPLAY;
      }

      if (HandleLetter(event) or HandleNumber(event) or HandleFunctional(event))
        return ContextEvent::UPDATE_DISPLAY;
    }

  if (event.type == sf::Event::MouseButtonReleased) {

    for (unsigned id = 0; id < buttons_.size(); id++)

      if (buttons_[id]->DetectInteraction({mouse_x, mouse_y}, event))

        switch ((CreatorInputPanelButton)id) {
        case CreatorInputPanelButton::EXIT:
          return ContextEvent::SWITCH_BACK_TO_CREATOR;
        case CreatorInputPanelButton::SAVE_LEVEL:
          UpdateLevel();
          target_.SaveLevel();
        case CreatorInputPanelButton::WIDTH_UP: {
          int width = std::stoi(
              input_panels_[(int)CreatorInputPanelTextField::WIDTH].GetText());
          width++;
          input_panels_[(int)CreatorInputPanelTextField::WIDTH].SetText(
              std::to_string(width));
        }
          return ContextEvent::UPDATE_DISPLAY;
        case CreatorInputPanelButton::WIDTH_DOWN: {
          int width = std::stoi(
              input_panels_[(int)CreatorInputPanelTextField::WIDTH].GetText());

          if (width < 1)
            return ContextEvent::UPDATE_DISPLAY;

          width--;
          input_panels_[(int)CreatorInputPanelTextField::WIDTH].SetText(
              std::to_string(width));
        }
          return ContextEvent::UPDATE_DISPLAY;
        case CreatorInputPanelButton::HEIGHT_DOWN: {
          int height = std::stoi(
              input_panels_[(int)CreatorInputPanelTextField::HEIGHT].GetText());

          if (height < 1)
            return ContextEvent::UPDATE_DISPLAY;

          height--;
          input_panels_[(int)CreatorInputPanelTextField::HEIGHT].SetText(
              std::to_string(height));
        }
          return ContextEvent::UPDATE_DISPLAY;
        case CreatorInputPanelButton::HEIGHT_UP: {
          int height = std::stoi(
              input_panels_[(int)CreatorInputPanelTextField::HEIGHT].GetText());
          height++;
          input_panels_[(int)CreatorInputPanelTextField::HEIGHT].SetText(
              std::to_string(height));
        }
          return ContextEvent::UPDATE_DISPLAY;
        }

    for (auto id = 0; id < input_panels_.size(); id++)
      if (input_panels_[id].DetectInteraction({mouse_x, mouse_y}, event)) {
        in_focus_ = (CreatorInputPanelTextField)id;
        input_panels_[id].SetText("");
        return ContextEvent::UPDATE_DISPLAY;
      }
    if (in_focus_ != CreatorInputPanelTextField::SIZE) {
      in_focus_ = CreatorInputPanelTextField::SIZE;
      return ContextEvent::UPDATE_DISPLAY;
    }
  } else {

    for (auto &button : buttons_)
      if (button->DetectHover({mouse_x, mouse_y}))
        change = true;

    for (auto &i : input_panels_)
      if (i.DetectHover({mouse_x, mouse_y}))
        change = true;
  }

  if (change)
    return ContextEvent::UPDATE_DISPLAY;

  return ContextEvent::NONE;
}

sfml_window::CreatorInputPanel *sfml_window::CreatorInputPanel::Clone() {
  return new CreatorInputPanel(*this);
}

GameEngine sfml_window::CreatorInputPanel::GetLevel() {
  return GameEngine(target_);
}

LevelInfo sfml_window::CreatorInputPanel::GetLevelInfo() {
  UpdateLevel();
  return target_;
}

std::string sfml_window::CreatorInputPanel::GetLevelDirectory() {
  return std::string("../levels/" + target_.GetName());
}

sfml_window::CreatorInputPanel::~CreatorInputPanel() {
  for (const auto &button : buttons_)
    delete button;
}

void sfml_window::CreatorInputPanel::LoadButtons() {
  std::string directory = "../sfml_window/assets/level_creator/";

  buttons_[(unsigned)CreatorInputPanelButton::EXIT] =
      new ImageButton(Rect(Coord(window_width_ - 36, 4), 32, 32),
                      directory + "back.png", YELLOW);
  buttons_[(unsigned)CreatorInputPanelButton::SAVE_LEVEL] =
      new ImageButton(Rect(Coord(window_width_ - 146, 4), 32, 32),
                      directory + "floppy-disk.png", BLUE);

  buttons_[(unsigned)CreatorInputPanelButton::WIDTH_UP] =
      new ImageButton(Rect({(int)window_width_ / 2 - 200 + 400, 200}, 32, 32),
                      directory + "right-arrow.png", YELLOW);
  buttons_[(unsigned)CreatorInputPanelButton::WIDTH_DOWN] =
      new ImageButton(Rect({(int)window_width_ / 2 - 236, 200}, 32, 32),
                      directory + "left-arrow.png", BLUE);

  buttons_[(unsigned)CreatorInputPanelButton::HEIGHT_UP] =
      new ImageButton(Rect({(int)window_width_ / 2 - 200 + 400, 250}, 32, 32),
                      directory + "right-arrow.png", YELLOW);
  buttons_[(unsigned)CreatorInputPanelButton::HEIGHT_DOWN] =
      new ImageButton(Rect({(int)window_width_ / 2 - 236, 250}, 32, 32),
                      directory + "left-arrow.png", BLUE);
}

void sfml_window::CreatorInputPanel::LoadBackground() {
  if (!background_texture_.loadFromFile("../levels/default/background.png"))
    throw "error";

  background_texture_.setSmooth(true);
  background_sprite_.setTexture(background_texture_);
  background_sprite_.setScale(
      (float)window_width_ / (float)background_texture_.getSize().x,
      (float)window_height_ / (float)background_texture_.getSize().y);
}

void sfml_window::CreatorInputPanel::LoadCreatorInputPanelTexts() {

  input_panels_[(int)CreatorInputPanelTextField::LEVEL_NAME] =
      ToggleTextButton({{(int)window_width_ / 2 - 200, 100}, 400, 30},
                       target_.GetName(), sf::Color::Blue, true);
  input_panels_[(int)CreatorInputPanelTextField::AUTHOR_NAME] =
      ToggleTextButton({{(int)window_width_ / 2 - 200, 150}, 400, 30},
                       "not yet implemented", sf::Color::Blue, true);

  input_panels_[(int)CreatorInputPanelTextField::WIDTH] = ToggleTextButton(
      {{(int)window_width_ / 2 - 200, 200}, 400, 30},
      std::to_string(target_.GetWidth()), sf::Color::Blue, true);

  input_panels_[(int)CreatorInputPanelTextField::HEIGHT] = ToggleTextButton(
      {{(int)window_width_ / 2 - 200, 250}, 400, 30},
      std::to_string(target_.GetHeight()), sf::Color::Blue, true);
}

void sfml_window::CreatorInputPanel::LoadLabels() {
  input_panels_labels_[(int)CreatorInputPanelTextField::LEVEL_NAME] =
      TextBox({40, 100}, "level name:", sf::Color::Blue, 24);
  input_panels_labels_[(int)CreatorInputPanelTextField::AUTHOR_NAME] =
      TextBox({40, 150}, "author name:", sf::Color::Blue, 24);
  input_panels_labels_[(int)CreatorInputPanelTextField::WIDTH] =
      TextBox({40, 200}, "level width:", sf::Color::Blue, 24);
  input_panels_labels_[(int)CreatorInputPanelTextField::HEIGHT] =
      TextBox({40, 250}, "level height:", sf::Color::Blue, 24);
}

void sfml_window::CreatorInputPanel::ClearHighlight() {
  for (ToggleTextButton &i : input_panels_)
    i.TurnOff();
  if (in_focus_ != CreatorInputPanelTextField::SIZE)
    input_panels_[(int)in_focus_].TurnOn();
}

void sfml_window::CreatorInputPanel::UpdateLevel() {

  std::string name =
      input_panels_[(int)CreatorInputPanelTextField::LEVEL_NAME].GetText();
  for (int i = name.size() - 1; i >= 0; i--)
    if (name[i] == ' ')
      name.erase(i);

  target_.SetName(name);

  // input_panels_[(int)CreatorInputPanelTextField::AUTHOR_NAME].GetText();

  target_.Resize(
      std::stoi(
          input_panels_[(int)CreatorInputPanelTextField::WIDTH].GetText()),
      std::stoi(
          input_panels_[(int)CreatorInputPanelTextField::HEIGHT].GetText()));
}
