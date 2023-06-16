workspace "EasyGL"
    configurations {"Debug","Release"}
    location "build"
    architecture ("x86_64")
project "EasyGL"
    kind "StaticLib"
    staticruntime "on"
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
    filter "system:windows"
        defines{"GLEW_STATIC"}
        libdirs 
        {
            "Dependencies/windows/glew-2.1.0/lib/Release/x64",
            "Dependencies/windows/glfw-3.3.8.bin.WIN64/lib-vc2022",
            "Dependencies/windows/glew-2.1.0/bin/Release/x64",
        }
        includedirs 
        {
            "Dependencies/windows/glew-2.1.0/include",
            "Dependencies/windows/glfw-3.3.8.bin.WIN64/include",
        }
        links { "glfw3_mt","glew32s","OpenGL32" }
    filter "system:linux" 
        links { "glfw3","GL","GLEW", "X11" ,"pthread","xcb", "Xau", "Xdmcp" }
    filter "configurations:Debug"
        defines {"CONFIG_DEBUG"}

    filter "configurations:Release"
        defines {"CONFIG_RELEASE"}
        optimize "On"

project "Sandbox"
    kind "ConsoleApp"
    staticruntime "on"
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
    filter "configurations:Debug"
        defines {"CONFIG_DEBUG"}
        links { "bin/EasyGL/Debug/EasyGL"}
    filter "configurations:Release"
        links { "bin/EasyGL/Release/EasyGL"}
        defines {"CONFIG_RELEASE"}
        optimize "On"
    filter "system:windows"
        defines{"GLEW_STATIC"}
        libdirs 
        {
            "Dependencies/windows/glew-2.1.0/lib/Release/x64",
            "Dependencies/windows/glfw-3.3.8.bin.WIN64/lib-vc2022",
        }
        includedirs 
        {
            "Dependencies/windows/glew-2.1.0/include",
            "Dependencies/windows/glfw-3.3.8.bin.WIN64/include",
        }
        links { "glfw3_mt","glew32s","OpenGL32"}
            
            
    filter "system:linux" 
        links { "glfw3","GL","GLEW", "X11" ,"pthread","xcb", "Xau", "Xdmcp"}
        
    
    
    

        
    