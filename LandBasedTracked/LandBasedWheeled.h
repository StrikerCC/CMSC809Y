//
// Created by cheng on 4/24/2020.
//
#pragma once

#include <memory>
#include <iostream>
#include "../LandBasedRobot/landbasedrobot.h"

namespace rwa3 {
    class LandBasedWheeled: public landbasedrobot{
    public:
        /// Basic constructor
        /// \param name - Name of the robot.
        /// \param x - X coordinate of the robot in the maze.
        /// \param y - Y coordinate of the robot in the maze.
        /// \param wheel_number -  Number of wheels mounted on the robot.
        /// \param wheel_type - Type of wheels mounted on the robot
        /// \param speed - Driving speed of the robot.
        /// \param width - Width of the base of the robot.
        /// \param length - Length of the base of the robot.
        /// \param height - Height of the base of the robot.
        /// \param capacity - Payload of the arm.
        LandBasedWheeled(const std::string name="UnknownLandBasedWheeled", int x=0, int y=0, int wheel_number=4, std::shared_ptr<std::string> wheel_type=nullptr, double speed=0.0, double width=1.0, double length=1.0, double height=1.0, double capacity=1.0) : landbasedrobot(name, x, y, speed, width, length, height, capacity), wheel_number{wheel_number}, wheel_type{wheel_type} {};
        /// deep copy constructor
        /// \param source - the LandBasedWheeled object being copied
        /// \return - a deep copy of LandBasedWheeled object
        LandBasedWheeled(const LandBasedWheeled &source) : LandBasedWheeled(source.name_, source.x_, source.y_, source.wheel_number, std::make_shared<std::string> (*source.wheel_type), source.speed_, source.width_, source.length_, source.height_, source.capacity_) {}
        virtual ~LandBasedWheeled(){
            std::cout << "LandBasedWheeled is released\n";
        };

        /// member function
        /// Move the robot up in the maze.
        /// \param x_ -
        /// \param y_ -
        void GoUp(int x_, int y_) override ;
        /// Move the robot down in the maze.
        /// \param x_  -
        /// \param y_  -
        void GoDown(int x_, int y_) override ;
        /// Move the robot left in the maze.
        /// \param x_ -
        /// \param y_ -
        void TurnLeft(int x_, int y_) override ;
        /// Move the robot right in the maze.
        /// \param x_ -
        /// \param y_ -
        void TurnRight(int x_, int y_) override ;
        /// Arm picks up an object.
        /// \param target -
        void PickUp(std::string target) override ;
        /// Arm releases an object.
        /// \param target -
        void Release(std::string target) override ;
    protected:
        int wheel_number;   /// Number of wheels mounted on the robot.
        std::shared_ptr<std::string> wheel_type;    /// Type of wheels mounted on the robot.
    };
}