//
// Created by mateu on 19.08.2024.
//

#ifndef COMMAND_H
#define COMMAND_H
#include <vector>
#include <string>


class Command {
public:
    // virtual ~Command() = 0;
    virtual bool validate(const std::vector<std::string>& args) const = 0;
    virtual void execute(const std::vector<std::string>& args) const = 0;
};



#endif //COMMAND_H
