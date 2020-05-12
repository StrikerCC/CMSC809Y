//
// Created by cheng on 4/24/2020.
//
#include "LandBasedTracked.h"

void rwa3::LandBasedTracked::GoUp(int x_, int y_) {
    std::cout << "LandBasedTracked::GoUp is called\n";
}

void rwa3::LandBasedTracked::GoDown(int x_, int y_) {
    std::cout << "LandBasedTracked::GoDown is called\n";
}

void rwa3::LandBasedTracked::TurnLeft(int x_, int y_) {
    std::cout << "LandBasedTracked::TurnLeft is called\n";
}

void rwa3::LandBasedTracked::TurnRight(int x_, int y_) {
    std::cout << "LandBasedTracked::TurnRight is called\n";
}

void rwa3::LandBasedTracked::PickUp(std::string target) {
    std::cout << "LandBasedTracked::PickUp is called\n";
}

void rwa3::LandBasedTracked::Release(std::string target) {
    std::cout << "LandBasedTracked::Release is called\n";
}
