project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir(TARGET_DIR)
	objdir(OBJ_DIR)

	files{
		"src/**.h",
		"src/**.cpp",
	}

	includedirs{
		"%{wks.location}/Flux/vendor/spdlog/include",
		"%{wks.location}/Flux/src",
		"%{wks.location}/Flux/vendor",
	}

	links{
		"Flux"
	}

	filter "system:windows"
		systemversion "latest"

		defines{
			"FLUX_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "FLUX_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "FLUX_RELEASE"
		runtime "Release"
		optimize  "on"

	filter "configurations:Dist"
		defines "FLUX_DIST"
		runtime "Release"
		optimize  "on"