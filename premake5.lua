workspace "EasyGL"
    configurations {"Debug","Release"}

project "EasyGL"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    objdir "bin-int/%{cfg.buildcfg}"
    files {"src/**.cpp","src/**.h"}
    includedirs
    {
        "src",
        "src/EasyGL",
        "src/EasyGL/render",
        "vendor"
    }
    
    links { "glfw3","GL","GLEW", "X11" ,"pthread","xcb", "Xau", "Xdmcp" }
    
    filter "configurations:Debug"
        defines {"CONFIG_DEBUG"}

        
    filter "configurations:Release"
        defines {"CONFIG_RELEASE"}
        optimize "On"
