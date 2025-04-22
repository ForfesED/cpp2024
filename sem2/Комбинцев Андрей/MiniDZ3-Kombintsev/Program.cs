
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <string>

using System.Linq;

1
{
	// Инициализация генератора случайных чисел
	std::srand(std::time(nullptr));

	// Создание окна
	sf::RenderWindow window(sf::VideoMode(400, 400), "Круглая кнопка");

	// Создание круглой кнопки
	sf::CircleShape button(100.f);
	button.setFillColor(sf::Color::Green);
	button.setPosition(100.f, 100.f);

	// Шрифт для текста
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// Если шрифт не загрузился, попробуем стандартный
		if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
		{
			return 1;
		}
	}

	// Текст на кнопке
	sf::Text buttonText("Нажми меня!", font, 24);
	buttonText.setFillColor(sf::Color::Black);
	buttonText.setPosition(150.f, 180.f);

	// Основной цикл программы
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			// Проверка нажатия на кнопку
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

					if (button.getGlobalBounds().contains(mousePosF))
					{
						// Меняем цвет кнопки при нажатии
						button.setFillColor(sf::Color::Red);
						window.draw(button);
						window.draw(buttonText);
						window.display();

						// Генерируем случайное время (от 10 до 60 секунд)
						int seconds = std::rand() % 51 + 10;

						// Команда выключения компьютера
						std::string command = "shutdown /s /t " + std::to_string(seconds);

                        // Выполняем команду
						system(command.c_str());

						// Закрываем окно
						window.close();
					}
				}
			}
		}

		// Отрисовка
		window.clear(sf::Color::White);
		window.draw(button);
		window.draw(buttonText);
		window.display();
	}

	return 0;
}