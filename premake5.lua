include "./vendor/premake/premake_customs/solutionitems.lua"
include "Dependencies.lua"

OUTPUT_DIR = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
TARGET_DIR = "%{wks.location}/bin/" .. OUTPUT_DIR .. "/%{prj.name}"
OBJ_DIR = "%{wks.location}/bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"


workspace "Flux"
    architecture "x64"
    startproject "Sandbox"

    configurations{
        "Debug",
        "Release",
        "Dist"
    }

    solutionitems{
        ".editorconfig"
    }

    flags{
        --"MultiProcessorCompile"
    }

group "Dependencies"
    include "vendor/premake"
    include "Flux/vendor/GLFW"
    include "Flux/vendor/Glad"
	include "Flux/vendor/ImGui"
group ""

include "Flux"
include "Sandbox"