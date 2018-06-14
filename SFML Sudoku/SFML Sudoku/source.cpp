#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>

using namespace std;

class sudoku{
protected:
	sf::RectangleShape kotak[81];
	sf::FloatRect kotakf[81];
	int count;
public:
	sudoku(){
		for(int x = 0; x<81; x++){
			kotak[x].setSize(sf::Vector2f(70,70));
			kotak[x].setOutlineColor(sf::Color::Red);
			kotak[x].setOutlineThickness(2);
		}
		count = 81;
	}

	void setposition(){
		float horisontal = 30, vertical = 30;
		int co = 0;
		for(int x = 0; x<81; x++){
			if(co == 9){
				horisontal = 30;
				vertical +=70;
				co = 0;
			}
			kotak[x].setPosition(sf::Vector2f(horisontal, vertical));
			horisontal+=70;
			co++;
		}
	}

	sf::RectangleShape gambar(int i){
		return kotak[i];
	}

	void setrectangle(){
		for(int x = 0; x<81; x++){
			kotakf[x] = kotak[x].getGlobalBounds();
		}
	}

	int getindexkotak(sf::Vector2f(localPosition)){
		for(int x = 0; x<81; x++){
			if(kotakf[x].contains(sf::Vector2f(localPosition))){
				return x;
			}
		}
	}
};

void main(){
    sf::RenderWindow window;
	sf::Style::Close;
    window.create(sf::VideoMode(900, 800), "My window");
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


	sf::RectangleShape background;
	background.setPosition(sf::Vector2f(30,30));
	background.setSize(sf::Vector2f(630,630));
	background.setOutlineThickness(5);
	background.setOutlineColor(sf::Color::Black);

	sudoku kotak;
	kotak.setposition();
	kotak.setrectangle();

	sf::FloatRect backgroundf;
	backgroundf = background.getGlobalBounds();


	while (window.isOpen()){
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);

			int poslx = localPosition.x;
			int posly = localPosition.y;
			cout<<"Local Position = "<<poslx<<", "<<posly<<endl;

			if(backgroundf.contains(sf::Vector2f(localPosition))){
				cout<<"Mouse In the Box\n";
				int x = kotak.getindexkotak(sf::Vector2f(localPosition));
				cout<<"Index Kotak Ke - "<<x<<endl;
			}

		}

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
		window.clear(sf::Color::White);
		window.draw(background);
		window.draw(tulisan);
		for(int x = 0; x<81; x++){
			window.draw(kotak.gambar(x));
		}
		window.display();
    }


}
