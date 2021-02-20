workspace "OpenGL-Framework"
	architecture "x64"
	startproject "OpenGL-Sandbox"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "ExternalLibs/GLFW/include"
IncludeDir["Glad"] = "ExternalLibs/Glad/include"
IncludeDir["glm"]  = "ExternalLibs/glm/glm"

include "ExternalLibs/GLFW"
include "ExternalLibs/Glad"

project "OpenGL-Sandbox"
    location "OpenGL-Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
	    "OpenGL-Framework/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.glm}",
        "ExternalLibs/spdlog/include"

    }

    links
    {
        "GLFW",
        "Glad",
        "OpenGL-Framework"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "GLFR_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "GLFR_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "GLFR_RELEASE"
        runtime "Release"
        optimize "On"

project "OpenGL-Framework"
    location "OpenGL-Framework"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp"
    }
    
    includedirs
    {
	    "OpenGL-Framework/src",
        "ExternalLibs/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.Glad}"
    }

    links
    {
        "GLFW",
        "Glad"
    }
    
    filter "system:windows"
        systemversion "latest"

        defines
        {
            "GLFR_PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE"
        }

    filter "configurations:Debug"
        defines "GLFR_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "GLFR_RELEASE"
        runtime "Release"
        optimize "On"