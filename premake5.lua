workspace "Kaybe"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Kaybe"
	location "Kaybe"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Kaybe/vendor/spdlog/include;"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"


		defines{
			"KB_PLATFORM_WINDOWS",
			"KB_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir.. "/Sandbox")
		}

	filter "configurations:Debug"
		
		defines "KB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		
		defines "KB_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		
		defines "KB_DIST"
		symbols "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Kaybe/vendor/spdlog/include;",
		"Kaybe/src"
	}

	links
	{
		"Kaybe"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"


		defines{
			"KB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		
		defines "KB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		
		defines "KB_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		
		defines "KB_DIST"
		symbols "On"







