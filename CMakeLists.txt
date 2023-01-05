cmake_minimum_required(VERSION 3.20)
project(embedded_prak)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS -pthread)


add_executable(embedded_prak SensorTag/m_pThread.cpp SensorTag/SensorTag.cpp SensorTag/SensorTag.h SensorTag/SensorConfiguration.cpp SensorTag/SensorConfiguration.h SensorTag/SensorCommunication.cpp SensorTag/SensorCommunication.h SensorTag/Motion.h CNamedSemaphore.cpp CNamedSemaphore.h sync_proc.cpp CBinarySemaphore.cpp CBinarySemaphore.h CCommQueue.cpp CCommQueue.h Global.h FWAssertion.h CMessage.h IMessageHandler.h)

TARGET_LINK_LIBRARIES(embedded_prak librt.so)