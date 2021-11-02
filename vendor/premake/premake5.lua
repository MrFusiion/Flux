project "Premake"
	kind "Utility"

	targetdir(TARGET_DIR)
	objdir(OBJ_DIR)

	files{
		"%{wks.location}/**premake5.lua"
	}

	postbuildmessage "Regenerating project files with Premake5!"
	postbuildcommands{
		"\"%{prj.location}bin/premake5\" %{_ACTION} --file=\"%{wks.location}premake5.lua\""
	}