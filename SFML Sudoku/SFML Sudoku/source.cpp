#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>

using namespace std;

void main(){
    sf::RenderWindow window;
	sf::Style::Close;
    window.create(sf::VideoMode(800, 600), "My window");
	window.setFramerateLimit(60);
	sf::Font huruf;
	if (!huruf.loadFromFile("Fonts/Roboto-Regular.ttf")){
    // error...
		cout<<"error";
	}
	//huruf.loadFromFile("arial.ttf");
	sf::Text tulisan;
	tulisan.setFont(huruf);
	tulisan.setString("Hi :)");
	tulisan.setCharacterSize(24); // in pixels, not points!

	sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
	
	// set the color
	tulisan.setColor(sf::Color::Red);

	// set the text style
	tulisan.setStyle(sf::Text::Bold | sf::Text::Underlined);

	// inside the main loop, between window.clear() and window.display()


	while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
		window.clear(sf::Color::White);
		window.draw(tulisan);
		window.display();
    }


}
