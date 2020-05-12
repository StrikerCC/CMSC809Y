//
// Created by cheng on 4/24/2020.
//
#pragma once
#include <memory>
#include <iostream>
#include "../LandBasedRobot/landbasedrobot.h"

namespace rwa3 {
    class LandBasedTracked : public landbasedrobot{
    public:
        /// Basic constructor
        /// \param name - Name of the robot.
        /// \param x - X coordinate of the robot in the maze
        /// \param y - Y coordinate of the robot in the maze
        /// \param track_type - Type of track mounted on the robot.
        /// \param speed - Driving speed of the robot.
        /// \param width - Width of the base of the robot.
        /// \param length - Length of the base of the robot.
        /// \param height - Height of the base of the robot.
        /// \param capacity - Payload of the arm.
        LandBasedTracked (std::string name="UnknownLandBasedTracked", int x=0, int y=0, std::shared_ptr<std::string> track_type=nullptr, double speed=0.0, double width=1.0, double length=1.0, double height=1.0, double capacity=1.0) : landbasedrobot(name, x, y, speed, width, length, height, capacity), track_type{track_type} {};
        /// deep copy constructor
        /// \param source - the LandBasedTracked object being copied
        /// \return - a deep copy of LandBasedTracked object
        LandBasedTracked(const LandBasedTracked &source) : LandBasedTracked(source.name_, source.x_, source.y_, std::make_shared<std::string> (*source.track_type), source.speed_, source.width_, source.length_, source.height_, source.capacity_) {}
        virtual ~LandBasedTracked() {
            std::cout << "LandBasedTracked is released\n";
        }

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
        std::shared_ptr<std::string> track_type;    /// Type of track mounted on the robot.
    };
}