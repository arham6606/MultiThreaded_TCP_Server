## 📌Project Title
# Multithreaded TCP Server in C++ (POSIX + std::thread)  

## 🚀 Overview
This project is a multithreaded TCP server built from scratch using:

- C++17
- POSIX sockets
- std::thread
- std::mutex

The goal was to deeply understand how backend infrastructure works at the system level — without frameworks, HTTP libraries, or abstractions.

This server:
- Accepts multiple TCP client connections
- Handles each client in a separate thread
- Manages shared state safely using mutexes
- Demonstrates race condition handling
- Shuts down cleanly
