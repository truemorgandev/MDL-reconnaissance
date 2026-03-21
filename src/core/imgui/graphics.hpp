#include "../../../external/imgui/imgui.h"
#include "../../../external/imgui/backends/imgui_impl_glfw.h"
#include "../../../external/imgui/backends/imgui_impl_opengl3.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdio>


class Graphics {
private:
     inline static GLFWwindow* window = nullptr;
public: 
    static bool init(){
        if (!glfwInit()) {
        std::fprintf(stderr, "Failed to init GLFW\n");
        return false;
        }
        window = glfwCreateWindow(900, 700, "[DEBUG] MDL-RECONNAISSANCE", nullptr, nullptr);
        if(!window){
            return false;
            glfwTerminate();
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);

        if(glewInit() != GLEW_OK){
            glfwTerminate();
            return false;
        }
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsLight();

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 130");

        return true;
    }

    static void run(){
        while(!glfwWindowShouldClose(window)){
            glfwPollEvents();

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            ImGui::Begin("test");
            ImGui::Text("IMGUI IS ALIVE [DEBUG]");

            if (ImGui::Button("Run all modules")) {
                
            }
            ImGui::End();

            ImGui::Render();

            int display_w, display_h;
            glfwGetFramebufferSize(window, &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClear(GL_COLOR_BUFFER_BIT);

            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            glfwSwapBuffers(window);
        }
    }
    static void terminate(){
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(window);
        glfwTerminate();
    }

};
