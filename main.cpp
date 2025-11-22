#include <SFML/Graphics.hpp>
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
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    float tst = 750;
    sf::RenderWindow window(sf::VideoMode({1920, 1200}), "3D Render", sf::Style::Default, sf::State::Windowed, settings);
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        //баг происходи когда полигон становится ребром камеры (на проекции он превращается в прямую)
        std::vector<polygon> zxc; 
        zxc.push_back(test.toDraw(cam, true)[0]);
        for (auto pol:test.toDraw(cam, true)) {
            std::vector<float> d1Proj = cam.projection(pol.d1);
            std::vector<float> d2Proj = cam.projection(pol.d2);
            std::vector<float> d3Proj = cam.projection(pol.d3);
            // std::cout << '(' << d1Proj[0] << ", " << d1Proj[1] << ") " << '(' << d2Proj[0] << ", " << d2Proj[1] << ") " << '(' << d3Proj[0] << ", " << d3Proj[1] << ")" << std::endl; 
            sf::ConvexShape triangle;
            triangle.setPointCount(3);
            // triangle.setPoint(0, {d1Proj[0], d1Proj[1]});
            // triangle.setPoint(1, {d2Proj[0], d2Proj[1]});
            // triangle.setPoint(2, {d3Proj[0], d3Proj[1]});
            
            triangle.setPoint(0, {500, 500});
            triangle.setPoint(1, {600, tst});
            triangle.setPoint(2, {700, 700});
            
            triangle.setFillColor(sf::Color::Red);
            triangle.setOutlineThickness(0);
            window.draw(triangle);
            
            // sf::ConvexShape line;
            // line.setPointCount(4);
            // line.setPoint(0, {d1Proj[0], d1Proj[1]});
            // line.setPoint(1, {d1Proj[0] + 1, d1Proj[1] + 1});
            // line.setPoint(2, {d2Proj[0] + 1, d2Proj[1] + 1});
            // line.setPoint(3, {d2Proj[0], d2Proj[1]});
            // window.draw(line);
            // sf::ConvexShape line1;
            // line1.setPointCount(4);
            // line1.setPoint(0, {d1Proj[0], d1Proj[1]});
            // line1.setPoint(1, {d1Proj[0] + 1, d1Proj[1] + 1});
            // line1.setPoint(2, {d3Proj[0] + 1, d3Proj[1] + 1});
            // line1.setPoint(3, {d3Proj[0], d3Proj[1]});
            // window.draw(line1);
            // sf::ConvexShape line2;
            // line2.setPointCount(4);
            // line2.setPoint(0, {d2Proj[0], d2Proj[1]});
            // line2.setPoint(1, {d2Proj[0] + 1, d2Proj[1] + 1});
            // line2.setPoint(2, {d3Proj[0] + 1, d3Proj[1] + 1});
            // line2.setPoint(3, {d3Proj[0], d3Proj[1]});
            // window.draw(line2);
        }
        tst -= 0.5;
        test.rotateXY(M_PI / 360);
        test.rotateXZ(M_PI / 360);
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
        window.display();
    }
    while (true){}
    return 0;
}

// int main() {
//     matrix3 mt(vec3(1, 0, 0), vec3(0, 0, 1), vec3(0, -1, 0));
//     matrix3 mt2(vec3(1, 0, 0), vec3(0, -1, 0), vec3(0, 0, 1));
//     mt2 = mt2 * mt;
//     std::cout << mt2.xVec << std::endl;
//     std::cout << mt2.yVec << std::endl;
//     std::cout << mt2.zVec << std::endl;
//     return 0;
// }