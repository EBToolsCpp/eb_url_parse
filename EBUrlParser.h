//
// Created by LQYHE on 2020/9/17.
//

#ifndef ERBAN_EBURLPARSER_H
#define ERBAN_EBURLPARSER_H


#include <string>

typedef std::string::size_type s_size;

class EBUrlParser {
public:

    int Parse(const std::string &url);

private:
    int ParseProtocolOrDomain(char *ch_url, char *pre_position, s_size position, s_size len);

    int ParseProtocol(char *ch_url, char *pre_position, s_size position, s_size len);

    int ParseDomain(char *ch_url, char *pre_position, s_size position, s_size len);

    int ParsePort(char *ch_url, char *pre_position, s_size position, s_size len);

    int ParsePath(char *ch_url, char *pre_position, s_size position, s_size len);

    int ParseParams(char *ch_url, char *pre_position, s_size position, s_size len);

public:
    void PrintResult() {
        m_protocol ? printf("protocol is  : %s \n", m_protocol) : printf("empty protocol");
        m_ip_domain ? printf("ip domain is : %s \n", m_ip_domain) : printf("empty ip domain");
        m_port ? printf("port is      : %s \n", m_port) : printf("empty port");
        m_path ? printf("path is      : %s \n", m_path) : printf("empty path");
        m_params ? printf("params is    : %s \n", m_params) : printf("empty path");
    }

private:
    char *m_protocol = nullptr;
    char *m_ip_domain = nullptr;
    char *m_port = nullptr;
    char *m_path = nullptr;
    char *m_params = nullptr;
};


#endif //ERBAN_EBURLPARSER_H
