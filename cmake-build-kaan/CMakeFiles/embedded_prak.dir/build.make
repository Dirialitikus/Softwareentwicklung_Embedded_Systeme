# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2022.3.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2022.3.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/cmake-build-kaan

# Include any dependencies generated for this target.
include CMakeFiles/embedded_prak.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/embedded_prak.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/embedded_prak.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/embedded_prak.dir/flags.make

CMakeFiles/embedded_prak.dir/SensorTag/m_pThread.cpp.o: CMakeFiles/embedded_prak.dir/flags.make
CMakeFiles/embedded_prak.dir/SensorTag/m_pThread.cpp.o: /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/SensorTag/m_pThread.cpp
CMakeFiles/embedded_prak.dir/SensorTag/m_pThread.cpp.o: CMakeFiles/embedded_prak.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/cmake-build-kaan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/embedded_prak.dir/SensorTag/m_pThread.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/embedded_prak.dir/SensorTag/m_pThread.cpp.o -MF CMakeFiles/embedded_prak.dir/SensorTag/m_pThread.cpp.o.d -o CMakeFiles/embedded_prak.dir/SensorTag/m_pThread.cpp.o -c /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/SensorTag/m_pThread.cpp

CMakeFiles/embedded_prak.dir/SensorTag/m_pThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embedded_prak.dir/SensorTag/m_pThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/SensorTag/m_pThread.cpp > CMakeFiles/embedded_prak.dir/SensorTag/m_pThread.cpp.i

CMakeFiles/embedded_prak.dir/SensorTag/m_pThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embedded_prak.dir/SensorTag/m_pThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/SensorTag/m_pThread.cpp -o CMakeFiles/embedded_prak.dir/SensorTag/m_pThread.cpp.s

CMakeFiles/embedded_prak.dir/SensorTag/SensorTag.cpp.o: CMakeFiles/embedded_prak.dir/flags.make
CMakeFiles/embedded_prak.dir/SensorTag/SensorTag.cpp.o: /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/SensorTag/SensorTag.cpp
CMakeFiles/embedded_prak.dir/SensorTag/SensorTag.cpp.o: CMakeFiles/embedded_prak.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/cmake-build-kaan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/embedded_prak.dir/SensorTag/SensorTag.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/embedded_prak.dir/SensorTag/SensorTag.cpp.o -MF CMakeFiles/embedded_prak.dir/SensorTag/SensorTag.cpp.o.d -o CMakeFiles/embedded_prak.dir/SensorTag/SensorTag.cpp.o -c /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/SensorTag/SensorTag.cpp

CMakeFiles/embedded_prak.dir/SensorTag/SensorTag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embedded_prak.dir/SensorTag/SensorTag.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/SensorTag/SensorTag.cpp > CMakeFiles/embedded_prak.dir/SensorTag/SensorTag.cpp.i

CMakeFiles/embedded_prak.dir/SensorTag/SensorTag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embedded_prak.dir/SensorTag/SensorTag.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/SensorTag/SensorTag.cpp -o CMakeFiles/embedded_prak.dir/SensorTag/SensorTag.cpp.s

CMakeFiles/embedded_prak.dir/SensorTag/SensorConfiguration.cpp.o: CMakeFiles/embedded_prak.dir/flags.make
CMakeFiles/embedded_prak.dir/SensorTag/SensorConfiguration.cpp.o: /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/SensorTag/SensorConfiguration.cpp
CMakeFiles/embedded_prak.dir/SensorTag/SensorConfiguration.cpp.o: CMakeFiles/embedded_prak.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/cmake-build-kaan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/embedded_prak.dir/SensorTag/SensorConfiguration.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/embedded_prak.dir/SensorTag/SensorConfiguration.cpp.o -MF CMakeFiles/embedded_prak.dir/SensorTag/SensorConfiguration.cpp.o.d -o CMakeFiles/embedded_prak.dir/SensorTag/SensorConfiguration.cpp.o -c /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/SensorTag/SensorConfiguration.cpp

CMakeFiles/embedded_prak.dir/SensorTag/SensorConfiguration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embedded_prak.dir/SensorTag/SensorConfiguration.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/SensorTag/SensorConfiguration.cpp > CMakeFiles/embedded_prak.dir/SensorTag/SensorConfiguration.cpp.i

CMakeFiles/embedded_prak.dir/SensorTag/SensorConfiguration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embedded_prak.dir/SensorTag/SensorConfiguration.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/SensorTag/SensorConfiguration.cpp -o CMakeFiles/embedded_prak.dir/SensorTag/SensorConfiguration.cpp.s

CMakeFiles/embedded_prak.dir/SensorTag/SensorCommunication.cpp.o: CMakeFiles/embedded_prak.dir/flags.make
CMakeFiles/embedded_prak.dir/SensorTag/SensorCommunication.cpp.o: /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/SensorTag/SensorCommunication.cpp
CMakeFiles/embedded_prak.dir/SensorTag/SensorCommunication.cpp.o: CMakeFiles/embedded_prak.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/cmake-build-kaan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/embedded_prak.dir/SensorTag/SensorCommunication.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/embedded_prak.dir/SensorTag/SensorCommunication.cpp.o -MF CMakeFiles/embedded_prak.dir/SensorTag/SensorCommunication.cpp.o.d -o CMakeFiles/embedded_prak.dir/SensorTag/SensorCommunication.cpp.o -c /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/SensorTag/SensorCommunication.cpp

CMakeFiles/embedded_prak.dir/SensorTag/SensorCommunication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embedded_prak.dir/SensorTag/SensorCommunication.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/SensorTag/SensorCommunication.cpp > CMakeFiles/embedded_prak.dir/SensorTag/SensorCommunication.cpp.i

CMakeFiles/embedded_prak.dir/SensorTag/SensorCommunication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embedded_prak.dir/SensorTag/SensorCommunication.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/SensorTag/SensorCommunication.cpp -o CMakeFiles/embedded_prak.dir/SensorTag/SensorCommunication.cpp.s

CMakeFiles/embedded_prak.dir/CNamedSemaphore.cpp.o: CMakeFiles/embedded_prak.dir/flags.make
CMakeFiles/embedded_prak.dir/CNamedSemaphore.cpp.o: /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/CNamedSemaphore.cpp
CMakeFiles/embedded_prak.dir/CNamedSemaphore.cpp.o: CMakeFiles/embedded_prak.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/cmake-build-kaan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/embedded_prak.dir/CNamedSemaphore.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/embedded_prak.dir/CNamedSemaphore.cpp.o -MF CMakeFiles/embedded_prak.dir/CNamedSemaphore.cpp.o.d -o CMakeFiles/embedded_prak.dir/CNamedSemaphore.cpp.o -c /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/CNamedSemaphore.cpp

CMakeFiles/embedded_prak.dir/CNamedSemaphore.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embedded_prak.dir/CNamedSemaphore.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/CNamedSemaphore.cpp > CMakeFiles/embedded_prak.dir/CNamedSemaphore.cpp.i

CMakeFiles/embedded_prak.dir/CNamedSemaphore.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embedded_prak.dir/CNamedSemaphore.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/CNamedSemaphore.cpp -o CMakeFiles/embedded_prak.dir/CNamedSemaphore.cpp.s

CMakeFiles/embedded_prak.dir/sync_proc.cpp.o: CMakeFiles/embedded_prak.dir/flags.make
CMakeFiles/embedded_prak.dir/sync_proc.cpp.o: /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/sync_proc.cpp
CMakeFiles/embedded_prak.dir/sync_proc.cpp.o: CMakeFiles/embedded_prak.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/cmake-build-kaan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/embedded_prak.dir/sync_proc.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/embedded_prak.dir/sync_proc.cpp.o -MF CMakeFiles/embedded_prak.dir/sync_proc.cpp.o.d -o CMakeFiles/embedded_prak.dir/sync_proc.cpp.o -c /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/sync_proc.cpp

CMakeFiles/embedded_prak.dir/sync_proc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embedded_prak.dir/sync_proc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/sync_proc.cpp > CMakeFiles/embedded_prak.dir/sync_proc.cpp.i

CMakeFiles/embedded_prak.dir/sync_proc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embedded_prak.dir/sync_proc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/sync_proc.cpp -o CMakeFiles/embedded_prak.dir/sync_proc.cpp.s

CMakeFiles/embedded_prak.dir/CBinarySemaphore.cpp.o: CMakeFiles/embedded_prak.dir/flags.make
CMakeFiles/embedded_prak.dir/CBinarySemaphore.cpp.o: /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/CBinarySemaphore.cpp
CMakeFiles/embedded_prak.dir/CBinarySemaphore.cpp.o: CMakeFiles/embedded_prak.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/cmake-build-kaan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/embedded_prak.dir/CBinarySemaphore.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/embedded_prak.dir/CBinarySemaphore.cpp.o -MF CMakeFiles/embedded_prak.dir/CBinarySemaphore.cpp.o.d -o CMakeFiles/embedded_prak.dir/CBinarySemaphore.cpp.o -c /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/CBinarySemaphore.cpp

CMakeFiles/embedded_prak.dir/CBinarySemaphore.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embedded_prak.dir/CBinarySemaphore.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/CBinarySemaphore.cpp > CMakeFiles/embedded_prak.dir/CBinarySemaphore.cpp.i

CMakeFiles/embedded_prak.dir/CBinarySemaphore.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embedded_prak.dir/CBinarySemaphore.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/CBinarySemaphore.cpp -o CMakeFiles/embedded_prak.dir/CBinarySemaphore.cpp.s

CMakeFiles/embedded_prak.dir/CCommQueue.cpp.o: CMakeFiles/embedded_prak.dir/flags.make
CMakeFiles/embedded_prak.dir/CCommQueue.cpp.o: /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/CCommQueue.cpp
CMakeFiles/embedded_prak.dir/CCommQueue.cpp.o: CMakeFiles/embedded_prak.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/cmake-build-kaan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/embedded_prak.dir/CCommQueue.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/embedded_prak.dir/CCommQueue.cpp.o -MF CMakeFiles/embedded_prak.dir/CCommQueue.cpp.o.d -o CMakeFiles/embedded_prak.dir/CCommQueue.cpp.o -c /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/CCommQueue.cpp

CMakeFiles/embedded_prak.dir/CCommQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/embedded_prak.dir/CCommQueue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/CCommQueue.cpp > CMakeFiles/embedded_prak.dir/CCommQueue.cpp.i

CMakeFiles/embedded_prak.dir/CCommQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/embedded_prak.dir/CCommQueue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/CCommQueue.cpp -o CMakeFiles/embedded_prak.dir/CCommQueue.cpp.s

# Object files for target embedded_prak
embedded_prak_OBJECTS = \
"CMakeFiles/embedded_prak.dir/SensorTag/m_pThread.cpp.o" \
"CMakeFiles/embedded_prak.dir/SensorTag/SensorTag.cpp.o" \
"CMakeFiles/embedded_prak.dir/SensorTag/SensorConfiguration.cpp.o" \
"CMakeFiles/embedded_prak.dir/SensorTag/SensorCommunication.cpp.o" \
"CMakeFiles/embedded_prak.dir/CNamedSemaphore.cpp.o" \
"CMakeFiles/embedded_prak.dir/sync_proc.cpp.o" \
"CMakeFiles/embedded_prak.dir/CBinarySemaphore.cpp.o" \
"CMakeFiles/embedded_prak.dir/CCommQueue.cpp.o"

# External object files for target embedded_prak
embedded_prak_EXTERNAL_OBJECTS =

embedded_prak: CMakeFiles/embedded_prak.dir/SensorTag/m_pThread.cpp.o
embedded_prak: CMakeFiles/embedded_prak.dir/SensorTag/SensorTag.cpp.o
embedded_prak: CMakeFiles/embedded_prak.dir/SensorTag/SensorConfiguration.cpp.o
embedded_prak: CMakeFiles/embedded_prak.dir/SensorTag/SensorCommunication.cpp.o
embedded_prak: CMakeFiles/embedded_prak.dir/CNamedSemaphore.cpp.o
embedded_prak: CMakeFiles/embedded_prak.dir/sync_proc.cpp.o
embedded_prak: CMakeFiles/embedded_prak.dir/CBinarySemaphore.cpp.o
embedded_prak: CMakeFiles/embedded_prak.dir/CCommQueue.cpp.o
embedded_prak: CMakeFiles/embedded_prak.dir/build.make
embedded_prak: CMakeFiles/embedded_prak.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/cmake-build-kaan/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable embedded_prak"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/embedded_prak.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/embedded_prak.dir/build: embedded_prak
.PHONY : CMakeFiles/embedded_prak.dir/build

CMakeFiles/embedded_prak.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/embedded_prak.dir/cmake_clean.cmake
.PHONY : CMakeFiles/embedded_prak.dir/clean

CMakeFiles/embedded_prak.dir/depend:
	cd /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/cmake-build-kaan && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/cmake-build-kaan /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/cmake-build-kaan /home/fs/CLionProjects/Softwareentwicklung_Embedded_Systeme/cmake-build-kaan/CMakeFiles/embedded_prak.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/embedded_prak.dir/depend

