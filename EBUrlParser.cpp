//
// Created by LQYHE on 2020/9/17.
//

#include "EBUrlParser.h"

int EBUrlParser::Parse(const std::string &url) {

    if (url.empty()) {
        return -1;
    }
    char *ch_url = const_cast<char *>(url.data());
    std::string::size_type len = url.size();
    int position = 0;
    char *pre_position = ch_url;
    for (; position < len; ++position) {
        switch (ch_url[position]) {
            case ':': {
                ch_url[position] = '\0';
                return ParseProtocolOrDomain(ch_url, pre_position, position, len);
            }
                break;
            case '/': {
                ch_url[position] = '\0';
                return ParseDomain(ch_url, pre_position, position, len);
            }
        }
    }
    return -4;
}

int EBUrlParser::ParseProtocolOrDomain(char *ch_url,  char *pre_position, std::string::size_type position,
                                       std::string::size_type len) {
    ++position;
    for (; position < len; ++position) {
        switch (ch_url[position]) {
            case '/': {
                ch_url[position] = '\0';
                return ParseProtocol(ch_url, pre_position, position, len);
            }
            default: {
                return ParseDomain(ch_url, pre_position, position, len);
            }
        }
    }
    return -5;
}

int EBUrlParser::ParseProtocol(char *ch_url,  char *pre_position, s_size position, s_size len) {
    ++position;
    if (ch_url[position] == '/') {
        ch_url[position] = '\0';
        m_protocol = pre_position;
        return ParseDomain(ch_url, pre_position, position, len);
    } else {
        return -2;
    }
}

int EBUrlParser::ParseDomain(char *ch_url,  char *pre_position, s_size position, s_size len) {
    ++position;
    pre_position = &ch_url[position];
    for (; position < len; ++position) {
        switch (ch_url[position]) {
            case ':': {
                ch_url[position] = '\0';
                m_ip_domain = pre_position;
                return ParsePort(ch_url, pre_position, position, len);
            }
            case '/':
            {
                ch_url[position] = '\0';
                m_ip_domain = pre_position;
                return ParsePath(ch_url,pre_position,position,len);
            }

        }
    }
    m_ip_domain = pre_position;
    return 0;
}

int EBUrlParser::ParsePort(char *ch_url,  char *pre_position, s_size position, s_size len) {
    ++position;
    pre_position = &ch_url[position];
    for (; position < len; ++position) {
        switch (ch_url[position]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                break;
            case '/': {
                ch_url[position] = '\0';
                m_port = pre_position;
                return ParsePath(ch_url, pre_position, position, len);
            }
            case '?': {
                ch_url[position] = '\0';
                m_port = pre_position;
                return ParseParams(ch_url, pre_position, position, len);
            }
            default:
                return -3;
        }
    }
    m_port = pre_position;
    return 0;
}

int EBUrlParser::ParsePath(char *ch_url,  char *pre_position, s_size position, s_size len) {
    ++position;
    pre_position = &ch_url[position];
    for (; position < len; ++position) {
        switch (ch_url[position]) {
            case '?': {
                ch_url[position] = '\0';
                m_path = pre_position;
                return ParseParams(ch_url, pre_position, position, len);
            }
            default:
                break;
        }
    }
    m_path = pre_position;
    return 0;
}

int EBUrlParser::ParseParams(char *ch_url,  char *pre_position, s_size position, s_size len) {
    ++position;
    pre_position = &ch_url[position];
    m_params = pre_position;
    return 0;
}
