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
    // std::vector<model> models{model(vec3(0, 10, 0), std::vector<polygon>{polygon(vec3(-3, -3, -3), vec3(-3, -3, 3), vec3(3, -3, -3))}),
                            //   model(vec3(0, -10, 0), std::vector<polygon>{polygon(vec3(-3, 3, -3), vec3(-3, 3, 3), vec3(3, 3, -3))}),
                            //   model(vec3(-10, 0, 0), std::vector<polygon>{polygon(vec3(3, -3, -3), vec3(3, -3, 3), vec3(3, 3, -3))})};
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
                                                   polygon(vec3(3, 3, 3), vec3(3, 3, -3), vec3(3, -3, -3))}),
                              model(vec3(0, -7, 0), std::vector<polygon>{polygon(vec3(-3, -3, -3), vec3(-3, -3, 3), vec3(3, -3, -3)),
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
    bool outline = true;
    std::vector<polygon> drawBuffer;
    vec3 light{0, -2, -1};
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
                } if (keyPressed->scancode == sf::Keyboard::Scancode::R) {
                    rotate = !rotate;
                } if (keyPressed->scancode == sf::Keyboard::Scancode::T) {
                    sleep = !sleep;
                } if (keyPressed->scancode == sf::Keyboard::Scancode::Tab) {
                    outline = !outline;
                }  
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) cam.position -= cam.basis.xVec;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) cam.position += cam.basis.xVec;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) cam.position += cam.basis.yVec;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) cam.position -= cam.basis.yVec;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) cam.position.z -= 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) cam.position.z += 1;
        window.clear(sf::Color::White);
        drawBuffer.clear();
        for (model mdl:models) {
            auto toDraw = mdl.toDraw(cam, outline);
            drawBuffer.reserve(drawBuffer.size() + toDraw.size());
            drawBuffer.insert(drawBuffer.end(), toDraw.begin(), toDraw.end());
        }
        std::sort(drawBuffer.begin(), drawBuffer.end(), [](polygon& pol1, polygon& pol2){return pol1.middle().y > pol2.middle().y;});
        for (auto pol:drawBuffer) {


            std::vector<float> d1Proj = cam.projection(pol.d1);
            std::vector<float> d2Proj = cam.projection(pol.d2);
            std::vector<float> d3Proj = cam.projection(pol.d3);        
            
            if (!outline) {
                sf::VertexArray triangle(sf::PrimitiveType::Triangles, 3);
                triangle[0].position = sf::Vector2f(d1Proj[0], d1Proj[1]);
                triangle[1].position = sf::Vector2f(d2Proj[0], d2Proj[1]);
                triangle[2].position = sf::Vector2f(d3Proj[0], d3Proj[1]);
                
                float angle = scalarMult(pol.normal(), cam.convertToCameraRotation(light).normalize());
                triangle[0].color = pol.color * sf::Color(72 * (0.2 + 0.8 * std::max(angle, 0.f)), 255 * (0.2 + 0.8 * std::max(angle, 0.f)), 69 * (0.2 + 0.8 * std::max(angle, 0.f)), 255);
                triangle[0].color.a = 255;
                triangle[1].color = pol.color * sf::Color(72 * (0.2 + 0.8 * std::max(angle, 0.f)), 255 * (0.2 + 0.8 * std::max(angle, 0.f)), 69 * (0.2 + 0.8 * std::max(angle, 0.f)), 255);
                triangle[1].color.a = 255;
                triangle[2].color = pol.color * sf::Color(72 * (0.2 + 0.8 * std::max(angle, 0.f)), 255 * (0.2 + 0.8 * std::max(angle, 0.f)), 69 * (0.2 + 0.8 * std::max(angle, 0.f)), 255);
                triangle[2].color.a = 255;
                window.draw(triangle);

            } else {
                sf::VertexArray triangle(sf::PrimitiveType::LineStrip, 4);
                triangle[0].position = sf::Vector2f(d1Proj[0], d1Proj[1]);
                triangle[1].position = sf::Vector2f(d2Proj[0], d2Proj[1]);
                triangle[2].position = sf::Vector2f(d3Proj[0], d3Proj[1]);
                triangle[3].position = sf::Vector2f(d1Proj[0], d1Proj[1]);
                
                triangle[0].color = sf::Color::Black;
                triangle[1].color = sf::Color::Black;
                triangle[2].color = sf::Color::Black;
                triangle[3].color = sf::Color::Black;
                window.draw(triangle);
            }

        }
        // light = light * getRotationMatrixXZ(M_PI / 360);
        if (rotate) {
            models[0].rotateXY(M_PI / 360);
            models[0].rotateXZ(M_PI / 360);
        }
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        // cam.rotateX(static_cast<double>(mousePos.x - static_cast<int>(xRes / 2)) / 100);
        // cam.rotateY(-static_cast<double>(mousePos.y - static_cast<int>(yRes / 2)) / 100);
        cam.rotate(-static_cast<float>(mousePos.x - static_cast<int>(xRes / 2)) / 100, static_cast<float>(mousePos.y - static_cast<int>(yRes / 2)) / 100);
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
                } if (keyPressed->scancode == sf::Keyboard::Scancode::T) {
                    sleep = !sleep;
                }
            }
            }
        }
    }
    while (true){}
    return 0;
}

//Разобраться с цветом
//При повороте модели можно записывать базис, а неосредственно вращать при переводе из локальных в глобальные координаты
//какая то проблема с цветом