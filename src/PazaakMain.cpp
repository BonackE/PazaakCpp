#include "PazaakMain.h"

PazaakMain::PazaakMain() {
	window = nullptr;
	glContext = nullptr;
	
}
PazaakMain::~PazaakMain(){
	
}
void PazaakMain::run() {
	init();
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	bool show_demo_window = false;
	
	SDL_Event e;
	bool quit = false;
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			ImGui_ImplSDL2_ProcessEvent(&e);
			if (e.type == SDL_QUIT) {
				quit = true;
			}

		}

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL2_NewFrame();
		ImGui::NewFrame();
		ImGui::SetNextWindowSize(ImVec2(400, 400));
		ImGui::SetNextWindowPos(ImVec2((io.DisplaySize.x - 400) / 2.0f, (io.DisplaySize.y - 400) / 2.0f));
		ImGui::Begin("Main Menu");
		ImGui::Spacing();
		if (ImGui::Button("New Game", ImVec2(360, 60))) {
			
			
		}
		if (ImGui::Button("Load Game", ImVec2(360, 60))) {
			// Handle load game action
		}
		ImGui::Separator();
		if (ImGui::Button("Quit", ImVec2(360, 60))) {
			quit = true;
		}
		ImGui::End();

		
		
		
		ImGui::Render();
		glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
		glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		SDL_GL_SwapWindow(window);
	}
	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void PazaakMain::init(){
	SDL_Init(SDL_INIT_EVERYTHING);
	const char* glsl_version = "#version 130";
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	window = SDL_CreateWindow("Dear ImGui SDL2+OpenGL3 example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
	glContext = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, glContext);
	SDL_GL_SetSwapInterval(1); // Enable vsync
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsLight();

	// Setup Platform/Renderer backends
	ImGui_ImplSDL2_InitForOpenGL(window, glContext);
	ImGui_ImplOpenGL3_Init(glsl_version);

	
}

