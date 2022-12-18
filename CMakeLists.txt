cmake_minimum_required(VERSION 3.20)
project(embedded_prak)

set(CMAKE_CXX_STANDARD 17)

add_executable(embedded_prak SensorTag/m_pThread.cpp SensorTag/SensorTag.cpp SensorTag/SensorTag.h SensorTag/SensorConfiguration.cpp SensorTag/SensorConfiguration.h SensorTag/SensorCommunication.cpp SensorTag/SensorCommunication.h SensorTag/Motion.h CNamedSemaphore.cpp CNamedSemaphore.h sync_proc.cpp)
