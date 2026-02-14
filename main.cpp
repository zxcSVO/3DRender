#include"libs/cppLibs.h"

int main()
{
    camera cam;
    model test(vec3(0, 7, 0), std::vector<polygon>{polygon(vec3(-3, -3, -3), vec3(-3, -3, 3), vec3(3, -3, -3)),
                                                   polygon(vec3(-3, -3, 3), vec3(3, -3, 3), vec3(3, -3, -3)),
                                                   polygon(vec3(-3, -3, 3), vec3(3, 3, 3), vec3(3, -3, 3)), 
                                                   polygon(vec3(-3, -3, 3), vec3(-3, 3, 3), vec3(3, 3, 3)), 
                                                   polygon(vec3(-3, 3, 3), vec3(-3, 3, -3), vec3(3, 3, 3)),
                                                   polygon(vec3(3, 3, -3), vec3(3, 3, 3), vec3(-3, 3, -3)), 
                                                   polygon(vec3(-3, 3, -3), vec3(-3, -3, -3), vec3(3, 3, -3)),
                                                   polygon(vec3(-3, -3, -3), vec3(3, -3, -3), vec3(3, 3, -3)),
                                                   polygon(vec3(-3, -3, -3), vec3(-3, 3, -3), vec3(-3, -3, 3)),
                                                   polygon(vec3(-3, -3, 3), vec3(-3, 3, -3), vec3(-3, 3, 3)),
                                                   polygon(vec3(3, -3, 3), vec3(3, 3, 3), vec3(3, -3, -3)),
                                                   polygon(vec3(3, 3, 3), vec3(3, 3, -3), vec3(3, -3, -3))});
    // std::vector<model> models{model(vec3(0, 10, 0), std::vector<polygon>{polygon(vec3(-3, -3, -3), vec3(-3, -3, 3), vec3(3, -3, -3))})};
    std::vector<model> models{model(vec3(0, 7, 0), std::vector<polygon>{polygon(vec3(-3, -3, -3), vec3(-3, -3, 3), vec3(3, -3, -3)),
                                                   polygon(vec3(-3, -3, 3), vec3(3, -3, 3), vec3(3, -3, -3)),
                                                   polygon(vec3(-3, -3, 3), vec3(3, 3, 3), vec3(3, -3, 3)), 
                                                   polygon(vec3(-3, -3, 3), vec3(-3, 3, 3), vec3(3, 3, 3)), 
                                                   polygon(vec3(-3, 3, 3), vec3(-3, 3, -3), vec3(3, 3, 3)),
                                                   polygon(vec3(3, 3, -3), vec3(3, 3, 3), vec3(-3, 3, -3)), 
                                                   polygon(vec3(-3, 3, -3), vec3(-3, -3, -3), vec3(3, 3, -3)),
                                                   polygon(vec3(-3, -3, -3), vec3(3, -3, -3), vec3(3, 3, -3)),
                                                   polygon(vec3(-3, -3, -3), vec3(-3, 3, -3), vec3(-3, -3, 3)),
                                                   polygon(vec3(-3, -3, 3), vec3(-3, 3, -3), vec3(-3, 3, 3)),
                                                   polygon(vec3(3, -3, 3), vec3(3, 3, 3), vec3(3, -3, -3)),
                                                   polygon(vec3(3, 3, 3), vec3(3, 3, -3), vec3(3, -3, -3))})};
    bool sleep = false;
    bool rotate = false;
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({xRes, yRes}), "3D Render", sf::Style::Default, sf::State::Windowed, settings);
    window.setVerticalSyncEnabled(true);
    sf::Mouse::setPosition({xRes / 2, yRes / 2}, window);
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                    return 0;
                } if (keyPressed->scancode == sf::Keyboard::Scancode::A) {
                    cam.rotateX(-M_PI / 90);
                } if (keyPressed->scancode == sf::Keyboard::Scancode::D) {
                    cam.rotateX(M_PI / 90);
                } if (keyPressed->scancode == sf::Keyboard::Scancode::W) {
                    cam.rotateY(M_PI / 90);
                } if (keyPressed->scancode == sf::Keyboard::Scancode::S) {
                    cam.rotateY(-M_PI / 90);
                } if (keyPressed->scancode == sf::Keyboard::Scancode::Space) {
                    sleep = !sleep;
                } if (keyPressed->scancode == sf::Keyboard::Scancode::R) {
                    rotate = !rotate;
                }
            }
        }

        window.clear();
        for (model mdl:models) {
            for (auto pol:mdl.toDraw(cam, true)) {
                std::vector<float> d1Proj = cam.projection(pol.d1);
                std::vector<float> d2Proj = cam.projection(pol.d2);
                std::vector<float> d3Proj = cam.projection(pol.d3);        
                
                sf::VertexArray triangle(sf::PrimitiveType::LineStrip, 4);
                triangle[0].position = sf::Vector2f(d1Proj[0], d1Proj[1]);
                triangle[1].position = sf::Vector2f(d2Proj[0], d2Proj[1]);
                triangle[2].position = sf::Vector2f(d3Proj[0], d3Proj[1]);
                triangle[3].position = sf::Vector2f(d1Proj[0], d1Proj[1]);

                triangle[0].color = sf::Color::White;
                triangle[1].color = sf::Color::White;
                triangle[2].color = sf::Color::White;
                triangle[3].color = sf::Color::White;
                window.draw(triangle);
            }
        }
        if (rotate) {
            models[0].rotateXY(M_PI / 360);
            models[0].rotateXZ(M_PI / 360);
        }
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        cam.rotateX(static_cast<double>(mousePos.x - static_cast<int>(xRes / 2)) / 100);
        cam.rotateY(-static_cast<double>(mousePos.y - static_cast<int>(yRes / 2)) / 100);
        sf::Mouse::setPosition({xRes / 2, yRes / 2}, window);
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
        window.display();
        while (sleep) {
            while (const std::optional event = window.pollEvent())
            {
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                    return 0;
                } if (keyPressed->scancode == sf::Keyboard::Scancode::Space) {
                    sleep = !sleep;
                }
            }
            }
        }
    }
    while (true){}
    return 0;
}

//Опять проблема с поворотом камеры