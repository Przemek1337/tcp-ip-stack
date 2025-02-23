//
// Created by mateu on 19.08.2024.
//

#ifndef ADDNEWDEVICECOMMAND_H
#define ADDNEWDEVICECOMMAND_H

#include "../command/command.h"
#include <string>
#include <vector>



class AddNewDeviceCommand : public Command {
public:
    bool validate(const std::vector<std::string>& args) const override;
    void execute(const std::vector<std::string> &args) const override;
};



#endif //ADDNEWDEVICECOMMAND_H
