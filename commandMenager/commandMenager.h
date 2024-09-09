//
// Created by mateu on 19.08.2024.
//

#ifndef COMMANDMENAGER_H
#define COMMANDMENAGER_H
#include <map>
#include <memory>


#include "../command/command.h"
#include "../addNewDeviceCommand/addNewDeviceCommand.h"

class CommandMenager {

    // map that contains all commands that are posible to input by user
    std::map<std::string, std::shared_ptr<Command>> commands;

    void print_error_message(std::string &command) {
        std::cout << command << " is invalid, try --help" << std::endl;
    }

public:
    CommandMenager() {
        // adds new commands to the map
        commands["new_device"] = std::make_shared<AddNewDeviceCommand>();
    }

    void executeComand(const std::vector<std::string>& commandParts) {
        if (commandParts.size() > 0) {
            std::string commandKey = commandParts[0];
            if (commands.find(commandKey) != commands.end()) {
                auto command = commands[commandKey];
                if (command->validate(commandParts)) {
                    command->execute(commandParts);
                }
            }
            else {
                print_error_message(commandKey);
            }

        }

    }

};

#endif //COMMANDMENAGER_H
