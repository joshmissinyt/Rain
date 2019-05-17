workspace "Rain"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-${cfg.architecture}"	

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Rain/vendor/GLFW/include"
IncludeDir["Glad"] = "Rain/vendor/glad/include"
IncludeDir["ImGui"] = "Rain/vendor/imgui"

group "Dependencies"
	include "Rain/vendor/GLFW"
	include "Rain/vendor/glad"
	include "Rain/vendor/imgui"
	
group ""

project "Rain"
	location "Rain"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "rnpch.h"
	pchsource "Rain/src/rnpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}
	
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"RN_PLATFORM_WINDOWS",
			"RN_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "RN_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "RN_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "RN_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Rain/vendor/spdlog/include",
		"Rain/src"
	}

	links
	{
		"Rain"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"RN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RN_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "RN_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "RN_DIST"
		runtime "Release"
		optimize "On"