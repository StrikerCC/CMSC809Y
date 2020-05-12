//
// Created by cheng on 4/24/2020.
//

#pragma once
#include <string>
#include <iostream>

namespace rwa3 {
    class landbasedrobot { /// abstract class
    public:
        /// Default constructor.
        /// \param name - Name of the robot.
        /// \param x - X coordinate of the robot in the maze.
        /// \param y - Y coordinate of the robot in the maze.
        /// Default constructor.
        /// \param name  - Name of the robot.
        /// \param x - X coordinate of the robot in the maze.
        /// \param y - Y coordinate of the robot in the maze.
        /// \param speed - Driving speed of the robot.
        /// \param width - Width of the base of the robot.
        /// \param length - Length of the base of the robot.
        /// \param height - Height of the base of the robot.
        /// \param capacity - Payload of the arm.
        landbasedrobot(std::string name, int x, int y, double speed, double width, double length, double height, double capacity) : name_{name}, x_{x}, y_{y}, speed_{speed}, width_{width}, length_{length}, height_{height}, capacity_{capacity}{};
        virtual ~landbasedrobot(){
            std::cout << "landbasedrobot is released\n";
        }

        /// member function
        /// Move the robot up in the maze.
        /// \param x_ -
        /// \param y_ -
        virtual void GoUp(int x_, int y_)=0;
        /// Move the robot down in the maze.
        /// \param x_  -
        /// \param y_  -
        virtual void GoDown(int x_, int y_)=0;
        /// Move the robot left in the maze.
        /// \param x_ -
        /// \param y_ -
        virtual void TurnLeft(int x_, int y_)=0;
        /// Move the robot right in the maze.
        /// \param x_ -
        /// \param y_ -
        virtual void TurnRight(int x_, int y_)=0;
        /// Arm picks up an object.
        /// \param target -
        virtual void PickUp(std::string target)=0;
        /// Arm releases an object.
        /// \param target -
        virtual void Release(std::string target)=0;

        ///--accessor or getter
        /// accessor of x coordinate
        /// \return X coordinate of the robot in the maze.
        int get_x() const{
            return this->x_;
        }
        /// accessor of y coordinate
        /// \return Y coordinate of the robot in the maze.
        int get_y() const{
            return this->y_;
        }
        /// accessor of robot name
        /// \return Name of the robot.
        std::string getName() const{
            return this->name_;
        }

    protected:
        std::string name_; /// Name of the robot.
        double speed_; /// Driving speed of the robot.
        double width_; /// Width of the base of the robot.
        double length_; /// Length of the base of the robot.
        double height_; /// Height of the base of the robot.
        double capacity_; /// Payload of the arm.
        int x_; /// X coordinate of the robot in the maze.
        int y_; /// Y coordinate of the robot in the maze.
    };
}