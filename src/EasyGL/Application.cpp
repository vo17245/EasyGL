#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <VertexBuffer.h>
#include <VertexArray.h>
#include <VertexBufferLayout.h>
#include <IndexBuffer.h>
#include <memory>
#include <Shader.h>
#include <Renderer.h>

static GLFWwindow* window;
int InitWindow()
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    return 0;
}
int InitGL()
{
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
      /* Problem: glewInit failed, something is seriously wrong. */
      fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
      return -1;
    }
    return 0;
}
int OnRender()
{

    return 0;
}
int main(void)
{   
    if(InitWindow()!=0)
        return -1;
    if(InitGL()!=0)
        return -1;

    float vertex[24] =
	{
		-0.5, -0.5, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0,
		 0.5, -0.5, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
		 0.0,  0.5, -0.5, 1.0, 0.0, 0.0, 1.0, 1.0
	};
    auto vb = std::unique_ptr<VertexBuffer>(new VertexBuffer(vertex, 24 * sizeof(float)));
    auto vbl = std::unique_ptr<VertexBufferLayout>(new VertexBufferLayout());
    vbl->Push<float>(4);
	vbl->Push<float>(4);
    auto va = std::unique_ptr<VertexArray>(new VertexArray());
    va->AddBuffer(*vb, *vbl);

    uint32_t indices[3] =
	{
		0,1,2
	};
    auto ib = std::make_unique<IndexBuffer>(indices,3);
    //create shader
	auto shader = std::unique_ptr<Shader>(new Shader("res/shader/base_vs.shader", "res/shader/base_fs.shader"));
    Renderer::ClearColor(0.45, 0.55, 0.6, 1.0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        Camera camera;
        camera.Move(0.3,0.1,0.1);
        Renderer::BeginScene(camera);
        Renderer::Submit(*va,*ib,*shader);
        Renderer::EndScene();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}