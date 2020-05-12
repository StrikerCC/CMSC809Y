//
// Created by cheng on 4/24/2020.
//
#include "landbasedrobot.h"

void rwa3::landbasedrobot::GoUp(int x_, int y_) {
    std::cout << "landbasedrobot::GoUp is called\n";
}// Move the robot up in the maze.

void rwa3::landbasedrobot::GoDown(int x_, int y_) {
    std::cout << "landbasedrobot::GoDown is called\n";
}// Move the robot down in the maze.

void rwa3::landbasedrobot::TurnLeft(int x_, int y_) {
    std::cout << "landbasedrobot::TurnLeft is called\n";
}// Move the robot left in the maze.
void rwa3::landbasedrobot::TurnRight(int x_, int y_) {

} // Move the robot right in the maze.
void rwa3::landbasedrobot::PickUp(std::string target) {
    std::cout << "landbasedrobot::PickUp is called\n";
} // Arm picks up an object.

void rwa3::landbasedrobot::Release(std::string target) {
    std::cout << "landbasedrobot::Release is called\n";
}

