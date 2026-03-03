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

# 🧠 Why This Project?
Modern backend systems are built on networking, concurrency, and shared memory management.

Instead of using frameworks, this project focuses on:

- Understanding bind / listen / accept at the OS level
- Exploring blocking I/O behavior
- Implementing thread-per-connection architecture
- Debugging race conditions
- Learning safe shared-state handling

# 🏗 Architecture
Main Thread:
- Creates server socket
- Binds to port
- Listens for incoming connections
- Accepts client connections

Worker Threads:
- One thread per client
- Handles recv/send loop
- Updates shared active client counter
- Uses mutex for synchronization

Shared State:
- active_clients counter
- Protected by std::mutex

# Diagram
## Client 1  ─┐
## Client 2  ─┼──> [ accept() ] ──> spawn thread ──> handle_client()
## Client 3  ─┘

# ⚙️ Technologies Used
- C++17
- POSIX socket API
- std::thread
- std::mutex
- gdb (debugging)
- valgrind (memory analysis)
- Linux (Ubuntu)

# 🧪 How to Run
- To compile run "make".
- to execute run ./bin/app

# 🔍 What I Learned
- How TCP connections are established at the system level
- Why blocking I/O limits scalability
- How race conditions appear under concurrency
- Why shared state is dangerous without synchronization
- How mutex locking affects execution flow
- Practical debugging using gdb
- Memory safety validation using valgrind

# 🚧 Future Improvements
- Implement thread pool instead of thread-per-connection
- Add non-blocking I/O using epoll
- Convert to HTTP server
- Add structured logging
- Graceful shutdown with signal handling

# 🏁 Final Note
This project focuses on fundamentals over frameworks.

Understanding concurrency and networking at this level builds the foundation for scalable backend systems.

# Contact
## Email:
m.arhamraj2004@gmail.com
## Linkdin: 
www.linkedin.com/in/-arham

This is infrastructur
