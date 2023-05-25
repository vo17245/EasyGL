workspace "EasyGL"
    configurations {"Debug","Release"}

project "EasyGL"
    kind "StaticLib"
    language "C++"
    targetdir "bin/%{prj.name}/%{cfg.buildcfg}"
    objdir "bin-int/%{prj.name}/%{cfg.buildcfg}"
    files {"EasyGL/src/EasyGL/**.cpp","EasyGL/src/EasyGL/**.h"}
    includedirs
    {
        "EasyGL/src",
        "EasyGL/src/EasyGL",
        "EasyGL/src/EasyGL/render",
        "EasyGL/src/EasyGL/core",
        "EasyGL/src/EasyGL/event",
        "EasyGL/vendor"
    }
    
    links { "glfw3","GL","GLEW", "X11" ,"pthread","xcb", "Xau", "Xdmcp" }
    
    filter "configurations:Debug"
        defines {"CONFIG_DEBUG"}

        
    filter "configurations:Release"
        defines {"CONFIG_RELEASE"}
        optimize "On"

project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{prj.name}/%{cfg.buildcfg}"
    objdir "bin-int/%{prj.name}/%{cfg.buildcfg}"
    files {"Sandbox/src/**.cpp","Sandbox/src/**.h"}
    includedirs
    {
        "EasyGL/src",
        "EasyGL/vendor",
        "EasyGL/src/EasyGL",
        "EasyGL/src/EasyGL/event"
        
    }
    
    libdirs { "bin/EasyGL/Debug" }
    
    
    filter "configurations:Debug"
        links { "bin/EasyGL/Debug/EasyGL","glfw3","GL","GLEW", "X11" ,"pthread","xcb", "Xau", "Xdmcp"}
        defines {"CONFIG_DEBUG"}

        
    filter "configurations:Release"
        links { "bin/EasyGL/Release/EasyGL","glfw3","GL","GLEW", "X11" ,"pthread","xcb", "Xau", "Xdmcp"}
        defines {"CONFIG_RELEASE"}
        optimize "On"