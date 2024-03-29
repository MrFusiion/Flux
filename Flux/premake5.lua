project "Flux"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir(TARGET_DIR)
    objdir(OBJ_DIR)

    pchheader "fluxpch.h"
	pchsource "src/fluxpch.cpp"


    files{
        "src/**.h",
		"src/**.cpp",
    }

    includedirs{
		"src",
		"%{INCLUDE_DIR.SpdLog}",
		"%{INCLUDE_DIR.GLFW}",
		"%{INCLUDE_DIR.Glad}",
		"%{INCLUDE_DIR.ImGui}",
	}

    links{
		"ImGui",
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

    filter "system:windows"
        systemversion "latest"

        defines{
            "FLUX_PLATFORM_WINDOWS",
            "FLUX_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. OUTPUT_DIR .. "/Sandbox")
		}

    filter "configurations:Debug"
        defines "FLUX_DEBUG"
        runtime "Debug"
        symbols "on"

		defines{
			"FLUX_ENABLE_ASSERTS",
		}

    filter "configurations:Release"
		defines "FLUX_RELEASE"
		runtime "Release"
		optimize "on"

    filter "configurations:Dist"
		defines "FLUX_DIST"
		runtime "Release"
		optimize "on"