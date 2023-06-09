cmake_minimum_required(VERSION 3.22)
project(collatz VERSION 0.0.1)

# abilita il supporto per i test, tra cui l'opzione BUILD_TESTING usata sotto
include(CTest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# richiedi l'uso di C++17, senza estensioni non-standard offerte dal compilatore usato
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# abilita warning
string(APPEND CMAKE_CXX_FLAGS
        " -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -Wcast-qual -Wformat=2"
        " -Wundef -Wshadow -Wcast-align -Wunused -Wnull-dereference"
        " -Wdouble-promotion -Wimplicit-fallthrough -Wextra-semi -Woverloaded-virtual"
        " -Wnon-virtual-dtor -Wold-style-cast")

# abilita address sanitizer e undefined-behaviour sanitizer in debug mode
string(APPEND CMAKE_CXX_FLAGS_DEBUG " -fsanitize=address,undefined -fno-omit-frame-pointer")
string(APPEND CMAKE_EXE_LINKER_FLAGS_DEBUG " -fsanitize=address,undefined -fno-omit-frame-pointer")

# richiedi il componente graphics della libreria SFML, versione 2.5
#   le dipendenze vengono identificate automaticamente
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

find_package(TGUI 0.10 REQUIRED)

add_executable(collatz main.cpp collatz/collatz.cpp events/events.cpp ui/ui.cpp ui/ui.h)
target_link_libraries(collatz PRIVATE sfml-graphics)
target_link_libraries(collatz PRIVATE TGUI::TGUI)

# se il testing e' abilitato...
#   per disabilitare il testing, passare -DBUILD_TESTING=OFF a cmake durante la fase di configurazione
if (BUILD_TESTING)
    # aggiungi l'eseguibile all.t
    add_executable(all.t test/all.t.cpp collatz/collatz.cpp collatz/collatz.t.cpp)
    # aggiungi l'eseguibile all.t alla lista dei test
    add_test(NAME all.t COMMAND all.t)
endif ()
