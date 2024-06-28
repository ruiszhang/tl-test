#ifndef TRACE_H
#define TRACE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>

#define READ_ONCE 5000
#define END_TIMER 20000 // cycles to run after trace all sent

// TODO: consider alias and other user fields
class Transaction {
public:
    uint32_t timestamp;
    uint8_t agentId;
    uint8_t channel;
    uint8_t opcode;
    paddr_t addr;
    uint8_t param;
    uint8_t reqsource;
    uint32_t pc;


    Transaction(uint32_t timestamp, uint8_t agentId, uint8_t channel, uint8_t opcode, paddr_t addr, uint8_t param, uint8_t reqsource, uint32_t pc) {
        this->timestamp = timestamp;
        this->agentId = agentId;
        this->channel = channel;
        this->opcode = opcode;
        this->addr = addr;
        this->param = param;
        this->reqsource = reqsource;
        this->pc = pc;
    }

    Transaction(std::string line) {
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }
        if (tokens.size() != 8) {
            std::cerr << "Error: invalid trace line: " << line << std::endl;
            exit(1);
        }
        this->timestamp = std::stoi(tokens[0]);
        this->agentId = std::stoi(tokens[1]);
        this->channel = std::stoi(tokens[2]);
        this->opcode = std::stoi(tokens[3]);
        this->addr = std::stoul(tokens[4]);
        this->param = std::stoul(tokens[5]);
        this->reqsource = std::stoul(tokens[6]);
        this->pc = std::stoul(tokens[7]);
    }

    std::string to_string() {
        std::ostringstream oss;
        oss << timestamp << ":" << (int)agentId << ":" << (int)channel << "," << (int)opcode << "," << std::hex << addr << "," << (int)param << "," << (int)reqsource << "," << (int)pc;
        return oss.str();
    }
};


#endif //TRACE_H