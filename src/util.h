#pragma once

#include <arpa/inet.h>

#include <cctype>
#include <string>
#include <vector>

#include "status.h"

namespace Util {
// sock util
sockaddr_in NewSockaddrInet(const std::string &host, uint32_t port);
Status SockConnect(std::string host, uint32_t port, int *fd);
int SockSend(int fd, const std::string &data);
int GetPeerAddr(int fd, std::string *addr, uint32_t *port);
bool IsPortInUse(int port);

// string util
std::string ToLower(std::string in);
void BytesToHuman(char *s, size_t size, uint64_t n);
void Trim(const std::string &in, const std::string &chars, std::string *out);
void Split(std::string in, std::string delim, std::vector<std::string> *out);

void ThreadSetName(const char *name);
}  // namespace Util