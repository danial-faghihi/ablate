target_sources(ablateLibrary
        PUBLIC
        monitor.hpp
        fieldErrorMonitor.hpp
        fieldErrorMonitor.cpp
        solutionErrorMonitor.hpp
        solutionErrorMonitor.cpp
        timeStepMonitor.hpp
        timeStepMonitor.cpp
        ignitionDelayPeakYi.hpp
        ignitionDelayPeakYi.cpp
        ignitionDelayTemperature.hpp
        ignitionDelayTemperature.cpp
        extractLineMonitor.hpp
        extractLineMonitor.cpp
        dmViewFromOptions.hpp
        dmViewFromOptions.cpp
        particleCount.hpp
        particleCount.cpp
        particleAverage.hpp
        particleAverage.cpp
        curveMonitor.hpp
        curveMonitor.cpp
        maxMinAverage.hpp
        maxMinAverage.cpp
        physicsTimeStep.hpp
        physicsTimeStep.cpp
        probes.hpp
        probes.cpp
        )

add_subdirectory(logs)
add_subdirectory(probes)