#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>

#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "Figure.h"
#include "Shader.h"

//=============================================================================
// ���������� ����������
//=============================================================================
	std::vector<model> models;
	glm::mat4 T; // �������, � ������� ������������� ��� ��������������
	glm::vec3 S, P, u; // ���������� ����� ����������
				  // �����, � ������� ��������� ������ ����������
				  // ������� ����������� �����
	float dist; // ��������������� ���������� - ���������� ����� S � P
	float fovy, aspect; // ���� ������ � ����������� ������ ���� ����������
	float fovy_work, aspect_work; // ������� ���������� ��� fovy � aspect
	float near_view, far_view; // ���������� �� ���� ���������� � �� ���������
	float n, f; // ������� ���������� ��� near � far
	float l, r, t, b; // ������� ��������������� ����������
					  // ��� �������� ��������� �����, ������,
					  // ������ � ������� ���������� � ���
	enum projType { Ortho, Frustum, Perspective } pType; // ��� ���������� ��������

	double lastX, lastY; // ��������� ������� �������
	bool LMBpressed;
	bool polygonMode = true;

	float lightAmbientR = 0.2f, lightAmbientG = 0.2f, lightAmbientB = 0.2f;
	float light2AmbientR = 0.2f, light2AmbientG = 0.2f, light2AmbientB = 0.2f;
	float lightDiffuseR = 0.5f, lightDiffuseG = 0.5f, lightDiffuseB = 0.5f;
	float light2DiffuseR = 0.5f, light2DiffuseG = 0.5f, light2DiffuseB = 0.5f;
	float lightSpecularR = 1.f, lightSpecularG = 1.f, lightSpecularB = 1.f;
	float light2SpecularR = 1.f, light2SpecularG = 1.f, light2SpecularB = 1.f;
	float lightDifSpecMult = 1.f;
	

	glm::mat4 lightM; // ��������� ������� ��� ��������� �����
	glm::mat4 light2M; // ��������� ������� ��� ������� ��������� �����
//=============================================================================

void initWorkPars() { // ������������� ������� ���������� ������
	n = near_view;
	f = far_view;
	fovy_work = fovy;
	aspect_work = aspect;

	float Vy = 2 * near_view * glm::tan(fovy / 2);
	float Vx = aspect * Vy;
	l = -Vx / 2;
	r = Vx / 2;
	b = -Vy / 2;
	t = Vy / 2;
	dist = glm::length(P - S);
	T = glm::lookAt(S, P, u);

}

void readFromFile(const char* fileName) { // ������ ����� �� ����� fileName
										  // ���������� � �������� �����
	std::ifstream in;
	in.open(fileName);
	if (in.is_open()) {
		// ���� ������� ������
		models.clear(); // ������� ��������� ������ �������

						// ��������� ���������� ��� ������ �� �����
		glm::mat4 M = glm::mat4(1.f); // ������� ��� ��������� ��������� �������
		glm::mat4 initM; // ������� ��� ���������� �������������� ������� �������
		std::vector<glm::mat4> transforms; // ���� ������ ��������������

		std::vector<mesh> figure; // ������ ����� ��������� ������
		float thickness = 2; // ������� �� ��������� �� ��������� 2
		
		// ������������ ����� ������ �� ���������� �� ���������
		glm::vec3 ambient = glm::vec3(0, 0, 0);
		glm::vec3 diffuse = glm::vec3(0, 0, 0);
		glm::vec3 specular = glm::vec3(0, 0, 0);
		float shininess = 1;

					   // ��������������� ������ � ������
		std::string str; // ������, � ������� ��������� ������ �����
		std::getline(in, str); // ��������� �� �������� ����� ������ ������
		while (in) { // ���� ��������� ������ ������� �������
					 // ������������ ������
			if ((str.find_first_not_of(" \t\r\n") != std::string::npos) && (str[0] != '#')) {
				// ����������� ������ �� ����� � �� �����������
				std::stringstream s(str); // ��������� ����� �� ������ str
				std::string cmd; // ���������� ��� ����� �������
				s >> cmd; // ��������� ��� �������

				if (cmd == "camera") { // ��������� ������
					float x, y, z; // ������������� ���������� ��� ������ �� �����, ����� �� ���� Intellisense
					s >> x >> y >> z; // ���������� ����� ����������
					S = glm::vec3(x, y, z);
					s >> x >> y >> z; // �����, � ������� ��������� ������ ����������
					P = glm::vec3(x, y, z);
					s >> x >> y >> z; // ������ ����������� �����
					u = glm::vec3(x, y, z);
				}
				else if (cmd == "screen") { // ��������� ���� ����������
					s >> fovy_work >> aspect >> near_view >> far_view; // ��������� �������
					fovy = glm::radians(fovy_work); // ������� ���� �� �������� � ��������
				}
				else if (cmd == "color") { // ���� �����
					float r, g, b;
					s >> r >> g >> b; // ��������� ��� ������������ �����
					ambient = glm::vec3(r, g, b) / 255.f;
					diffuse = ambient;
					specular = ambient;

				}
				else if (cmd == "ambient") { // ����������� �������� ���������� ����
					float r, g, b;
					s >> r >> g >> b; // ��������� ��� ������������ �����
					ambient = glm::vec3(r, g, b);
				}
				else if (cmd == "diffuse") { // ����������� �������� ���������� ����
					float r, g, b;
					s >> r >> g >> b; // ��������� ��� ������������ �����
					diffuse = glm::vec3(r, g, b);
				}
				else if (cmd == "specular") { // // ����������� �������� �����
					float r, g, b;
					s >> r >> g >> b; // ��������� ��� ������������ �����
					specular = glm::vec3(r, g, b);
				}
				else if (cmd == "shininess") { // ������� �����������
					s >> shininess;
				}
				else if (cmd == "thickness") { // ������� �����
					s >> thickness; // ��������� �������� �������
				}
				else if (cmd == "mesh") { // ����� �����
					std::vector<vertex> vertices; // ������ �����
					int N, K; // ���������� ����� � �������������
					s >> N >> K;
					std::string str1; // �������������� ������ ��� ������ �� �����
					while (N > 0) { // ���� �� ��� ����� �������
						std::getline(in, str1); // ��������� � str1 �� �������� ����� ��������� ������
										   // ��� ��� ���� ����������, �� �� ����� ����� ��������� �� �����
						if ((str1.find_first_not_of(" \t\r\n") != std::string::npos) && (str1[0] != '#')) {
							// ����������� ������ �� ����� � �� �����������
							// ������ � ��� ���� ���������
							float x, y, z; // ���������� ��� ����������
							float nx, ny, nz; // ���������� ��� ���������� ��������� �������
							std::stringstream s1(str1); // ��� ���� ��������� ����� �� ������ str1
							s1 >> x >> y >> z;
							s1 >> nx >> ny >> nz;
							vertices.push_back({ glm::vec3(x, y, z), glm::vec3(nx, ny, nz)}); // ��������� ����� � ������
							N--; // ��������� ������� ����� ��������� ���������� �����
						}

					}
					std::vector<GLuint> indices; // ������ �������� ������ �������������
					while (K > 0) { // ���� �� ������� ��� ������������
						std::getline(in, str1); // ��������� � str1 �� �������� ����� ��������� ������
												// ��� ��� ���� ����������, �� �� ����� ����� ��������� �� �����
						if ((str1.find_first_not_of(" \t\r\n") != std::string::npos) && (str1[0] != '#')) {
							// ����������� ������ �� ����� � �� �����������
							// ������ � ��� ������ �������� ������ ������������
							GLuint x; // ���������� ��� ����������
							std::stringstream s1(str1); // ��� ���� ��������� ����� �� ������ str1
							for (int i = 0; i < 3; i++) { // ��� ����
								s1 >> x; // ��������� ������
								indices.push_back(x); // ��������� ������ � ������ indices
							}
							K--; // ��������� ������� ����� ��������� ���������� �����
						}
					}
					// ��� ����� � ������� �������, ���������� ��� � ������ ��� � ������ figure
					figure.push_back(mesh(vertices, indices, { ambient, diffuse, specular, shininess }));
				}
				else if (cmd == "model") {
					float mVcx, mVcy, mVcz, mVx, mVy, mVz; // ��������� ������� model
					s >> mVcx >> mVcy >> mVcz >> mVx >> mVy >> mVz; // ��������� �������� ����������
					float S = mVx / mVy < 1 ? 2.f / mVy : 2.f / mVx;
					// ����� ����� �������� �� ������ ��������� � ������ �������
					// ����� �������� �������� ���������������
					initM = glm::scale(glm::vec3(S)) * glm::translate(glm::vec3(-mVcx, -mVcy, -mVcz));
					figure.clear();
				}
				else if (cmd == "figure") {
					models.push_back(model(figure, M * initM)); // ��������� ������� � ������
				}
				else if (cmd == "translate") {
					float Tx, Ty, Tz; // ��������� �������������� ��������
					s >> Tx >> Ty >> Tz; // ��������� ���������
					M = glm::translate(glm::vec3(Tx, Ty, Tz)) * M; // ��������� ������� � ������ ��������������
				}
				else if (cmd == "scale") {
					float S; // �������� ���������������
					s >> S; // ��������� ��������
					M = glm::scale(glm::vec3(S, S, S)) * M; // ��������� ��������������� � ������ ��������������
				}
				else if (cmd == "rotate") {
					float theta; // ���� �������� � ��������
					float nx, ny, nz; // ���������� ������������� ������� ��� ��������
					s >> theta >> nx >> ny >> nz; // ��������� ���������
												  // ��������� �������� � ������ ��������������
					M = glm::rotate(glm::radians(theta), glm::vec3(nx, ny, nz)) * M;
				}
				else if (cmd == "pushTransform") {
					transforms.push_back(M); // ��������� ������� � ����
				}
				else if (cmd == "popTransform") {
					M = transforms.back(); // �������� ������� ������� �����
					transforms.pop_back(); // ���������� ������� �� �����
				}

			}
			// ��������� ��������� ������
			getline(in, str);
		}
		initWorkPars();
	}
}

// ���������� ������� Resize
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

// �������� ������ ����� P
glm::mat4 rotateP(float theta, glm::vec3 n, glm::vec3 P) {
	return glm::translate(glm::vec3(P.x, P.y, P.z)) *
		(rotate(theta, n) * glm::translate(glm::vec3(-P.x, -P.y, -P.z)));
}

// ���������� ��������� �������
void cursorPos_callback(GLFWwindow* window, double xpos, double ypos) {
	// ��������� ������, �������� ��� ��������
	glm::vec3 n = glm::vec3(lastY - ypos, lastX - xpos, 0);
	// ������� ������� ��������
	glm::mat4 M = glm::rotate(glm::length(n) * 0.002f, n);
	// ������� ���� (0, 0, -1), �� ������� ������� �����������
	glm::vec3 P = M * glm::vec4(0, 0, -1, 1);
	// ��������� � ��������������� ������� � ����� ������� ��������� �����������
	T = glm::lookAt(glm::vec3(0), P, u) * T;
	lastX = xpos;
	lastY = ypos;
}

// ���������� ������� ������� ��� ���������� �������
void cursorPosSave_callback(GLFWwindow* window, double xpos, double ypos) {
	if (LMBpressed) {
		//// ��������� ������, �������� ��� ��������
		//glm::vec3 n = glm::vec3(lastY - ypos, lastX - xpos, 0);
		//// ������� ������� ��������
		//glm::mat4 M = glm::rotate(glm::length(n) * 0.002f, n);
		//// ������� ���� (0, 0, -1), �� ������� ������� �����������
		//glm::vec3 P = M * glm::vec4(0, 0, -1, 1);
		//// ��������� � ��������������� ������� � ����� ������� ��������� �����������
		//T = glm::lookAt(glm::vec3(0), P, u) * T;
		glm::mat4 M = rotateP(0.1, glm::vec3(lastY - ypos, lastX - xpos, 0), glm::vec3(0, 0, -dist)); // ������� �������� ������������ ����� P
		glm::vec3 u_new = glm::mat3(M) * glm::vec3(0, 1, 0); // �������� ����������� �����
		glm::vec3 S_new = glm::normalize(M * glm::vec4(0, 0, 0, 1)); // �������� ������ ���������
																	 // ������� � ��� � ������� ������ ��������� � ����� �����, � �����������
																	 // ���������� - � ����� P
		T = glm::lookAt(S_new, glm::vec3(0, 0, -dist), glm::vec3(0, 1.f, 0)) * T;
	}
	lastX = xpos;
	lastY = ypos;
}

// ���������� ������� ������
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (action != GLFW_RELEASE) { // ���� ������� ������
		switch (key) { // ����������� �������������� �������
		case GLFW_KEY_3:
			pType = Perspective;
			break;
		case GLFW_KEY_2:
			pType = Frustum;
			break;
		case GLFW_KEY_1:
			pType = Ortho;
			break;
		case GLFW_KEY_0:
			if (polygonMode) {
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			else {
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			polygonMode = !polygonMode;
			break;
		case GLFW_KEY_4:
			if (mode == GLFW_MOD_SHIFT) {
				light2M *= T;
				light2M *= glm::translate(glm::vec3(0, 0, -0.3f));
				light2M *= glm::inverse(T);
			}
			else {
				light2M *= T;
				light2M *= glm::translate(glm::vec3(0, 0, 0.3f));
				light2M *= glm::inverse(T);
			}
			break;
		case GLFW_KEY_5:
			if (mode == GLFW_MOD_SHIFT) {
				light2M *= T;
				light2M *= glm::translate(glm::vec3(0, -0.3f, 0));
				light2M *= glm::inverse(T);
			}
			else {
				light2M *= T;
				light2M *= glm::translate(glm::vec3(0, 0.3f, 0));
				light2M *= glm::inverse(T);
			}
			break;
		case GLFW_KEY_6:
			if (mode == GLFW_MOD_SHIFT) {
				light2M *= T;
				light2M *= glm::translate(glm::vec3(-0.3f, 0, 0));
				light2M *= glm::inverse(T);
			}
			else {
				light2M *= T;
				light2M *= glm::translate(glm::vec3(0.3f, 0, 0));
				light2M *= glm::inverse(T);
			}
			break;
		case GLFW_KEY_7: 
			if (mode == GLFW_MOD_SHIFT) {
				lightDifSpecMult *= 1.f / 1.1f;
			}
			else
				lightDifSpecMult *= 1.1f;
			break;
			// (0, 0, 0) (0, 0, -1) (0, 1, 0)
		case GLFW_KEY_F3: {
			OPENFILENAME openFileDialog; // ������ �������� �����
			char fileName[260]; // ����� ��� ����� �����
								// ������������� ��������� �������
			ZeroMemory(&openFileDialog, sizeof(openFileDialog));
			openFileDialog.lStructSize = sizeof(openFileDialog);
			openFileDialog.hwndOwner = NULL;
			openFileDialog.lpstrFile = fileName;
			openFileDialog.lpstrFile[0] = '\0';
			openFileDialog.nMaxFile = sizeof(fileName);
			openFileDialog.lpstrFilter = "Text files (*.txt)\0*.txt\0All files 2007\0*.*\0";
			openFileDialog.nFilterIndex = 1;
			openFileDialog.lpstrFileTitle = NULL;
			openFileDialog.nMaxFileTitle = 0;
			openFileDialog.lpstrInitialDir = NULL;
			openFileDialog.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
			// ������ ��������� ������� � ��������� ����������
			if (GetOpenFileName(&openFileDialog)) {
				// ���� ���� ������ �������
				readFromFile(fileName);
			}
			break;
		}
		case GLFW_KEY_F5:
			if (glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED) {
				// ���������� ������
				glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
				// ����������� ���������� ��������� �������
				glfwSetCursorPosCallback(window, cursorPosSave_callback);
			}
			else {
				// ����������� ������
				glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
				// ���������� ���������� ��������� �������
				glfwSetCursorPosCallback(window, cursorPos_callback);
			}
			break;
		case GLFW_KEY_W:
			if (mode == GLFW_MOD_SHIFT) {
				T =glm::lookAt(glm::vec3(0, 0, -0.1), glm::vec3(0, 0, -2), glm::vec3(0, 1, 0)) * T;
			}
			else {
				T =glm::lookAt(glm::vec3(0, 0, -1), glm::vec3(0, 0, -2), glm::vec3(0, 1, 0)) * T;
			}
			break;
		case GLFW_KEY_S:
			if (mode == GLFW_MOD_SHIFT) { // TODO
				T =glm::lookAt(glm::vec3(0, 0, 0.1), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)) * T;
			}
			else {
				T =glm::lookAt(glm::vec3(0, 0, 1), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)) * T;
			}
			break;
		case GLFW_KEY_A:
			if (mode == GLFW_MOD_SHIFT) { // TODO
				T =glm::lookAt(glm::vec3(-0.1, 0, 0), glm::vec3(-0.1, 0, -1), glm::vec3(0, 1, 0)) * T;
			}
			else {
				T =glm::lookAt(glm::vec3(-1, 0, 0), glm::vec3(-1, 0, -1), glm::vec3(0, 1, 0)) * T;
			}
			break;
		case GLFW_KEY_D:
			if (mode == GLFW_MOD_SHIFT) {
				T =glm::lookAt(glm::vec3(0.1, 0, 0), glm::vec3(0.1, 0, -1), glm::vec3(0, 1, 0)) * T;
			}
			else {
				T =glm::lookAt(glm::vec3(1, 0, 0), glm::vec3(1, 0, -1), glm::vec3(0, 1, 0)) * T;
			}
			break;
		case GLFW_KEY_R: {
			glm::vec3 u_new = glm::mat3(glm::rotate(0.1f, glm::vec3(0, 0, 1))) * glm::vec3(0, 1, 0);
			T =glm::lookAt(glm::vec3(0, 0, 0), glm::vec3(0, 0, -1), u_new) * T;
			break;
		}
		case GLFW_KEY_Y: {
			glm::vec3 u_new = glm::mat3(glm::rotate(-0.1f, glm::vec3(0, 0, 1))) * glm::vec3(0, 1, 0);
			T =glm::lookAt(glm::vec3(0, 0, 0), glm::vec3(0, 0, -1), u_new) * T;
			break;
		}
		case GLFW_KEY_T: {
			if (mode == GLFW_MOD_SHIFT) {
				glm::mat4 M = rotateP(0.1, glm::vec3(1, 0, 0), glm::vec3(0, 0, -dist)); // ������� �������� ������������ ����� P
				glm::vec3 u_new = glm::mat3(M) * glm::vec3(0, 1, 0); // �������� ����������� �����
				glm::vec3 S_new = glm::normalize(M * glm::vec4(0, 0, 0, 1)); // �������� ������ ���������
															  // ������� � ��� � ������� ������ ��������� � ����� �����, � �����������
															  // ���������� - � ����� P
				T =glm::lookAt(S_new, glm::vec3(0, 0, -dist), u_new) * T;

			}
			else {
				glm::mat4 M = glm::rotate(0.1f, glm::vec3(1, 0, 0)); // ������� �������� ������������ Ox
				glm::vec3 u_new = glm::mat3(M) * glm::vec3(0, 1, 0); // �������� ����������� �����
				glm::vec3 P_new = glm::normalize(M * glm::vec4(0, 0, -1, 1)); // �������� �����, � ������� ������� �����������
				T =glm::lookAt(glm::vec3(0, 0, 0), P_new, u_new) * T;
			}
			break;
		}
		case GLFW_KEY_G: {
			if (mode == GLFW_MOD_SHIFT) {
				glm::mat4 M = rotateP(-0.1f, glm::vec3(1, 0, 0), glm::vec3(0, 0, -dist)); // ������� �������� ������������ ����� P
				glm::vec3 u_new = glm::mat3(M) * glm::vec3(0, 1, 0); // �������� ����������� �����
				glm::vec3 S_new = glm::normalize(M * glm::vec4(0, 0, 0, 1)); // �������� ������ ���������
															  // ������� � ��� � ������� ������ ��������� � ����� �����, � �����������
															  // ���������� - � ����� P
				T =glm::lookAt(S_new, glm::vec3(0, 0, -dist), u_new) * T;

			}
			else {
				glm::mat4 M = glm::rotate(-0.1f, glm::vec3(1, 0, 0)); // ������� �������� ������������ Ox
				glm::vec3 u_new = glm::mat3(M) * glm::vec3(0, 1, 0); // �������� ����������� �����
				glm::vec3 P_new = glm::normalize(M * glm::vec4(0, 0, -1, 1)); // �������� �����, � ������� ������� �����������
				T =glm::lookAt(glm::vec3(0, 0, 0), P_new, u_new) * T;
			}
			break;
		}
		case GLFW_KEY_F: {
			if (mode == GLFW_MOD_SHIFT) {
				glm::mat4 M = rotateP(0.1, glm::vec3(0, 1, 0), glm::vec3(0, 0, -dist)); // ������� �������� ������������ ����� P
				glm::vec3 u_new = glm::mat3(M) * glm::vec3(0, 1, 0); // �������� ����������� �����
				glm::vec3 S_new = glm::normalize(M * glm::vec4(0, 0, 0, 1)); // �������� ������ ���������
															  // ������� � ��� � ������� ������ ��������� � ����� �����, � �����������
															  // ���������� - � ����� P
				T =glm::lookAt(S_new, glm::vec3(0, 0, -dist), u_new) * T;

			}
			else {
				glm::mat4 M = glm::rotate(0.1f, glm::vec3(0, 1, 0)); // ������� �������� ������������ Ox
				glm::vec3 u_new = glm::mat3(M) * glm::vec3(0, 1, 0); // �������� ����������� �����
				glm::vec3 P_new = glm::normalize(M * glm::vec4(0, 0, -1, 1)); // �������� �����, � ������� ������� �����������
				T =glm::lookAt(glm::vec3(0, 0, 0), P_new, u_new) * T;
			}
			break;
		}
		case GLFW_KEY_H: {
			if (mode == GLFW_MOD_SHIFT) {
				glm::mat4 M = rotateP(-0.1, glm::vec3(0, 1, 0), glm::vec3(0, 0, -dist)); // ������� �������� ������������ ����� P
				glm::vec3 u_new = glm::mat3(M) * glm::vec3(0, 1, 0); // �������� ����������� �����
				glm::vec3 S_new = glm::normalize(M * glm::vec4(0, 0, 0, 1)); // �������� ������ ���������
															  // ������� � ��� � ������� ������ ��������� � ����� �����, � �����������
															  // ���������� - � ����� P
				T =glm::lookAt(S_new, glm::vec3(0, 0, -dist), u_new) * T;

			}
			else {
				glm::mat4 M = glm::rotate(-0.1f, glm::vec3(0, 1, 0)); // ������� �������� ������������ Ox
				glm::vec3 u_new = glm::mat3(M) * glm::vec3(0, 1, 0); // �������� ����������� �����
				glm::vec3 P_new = glm::normalize(M * glm::vec4(0, 0, -1, 1)); // �������� �����, � ������� ������� �����������
				T =glm::lookAt(glm::vec3(0, 0, 0), P_new, u_new) * T;
			}
			break;
		}
		case GLFW_KEY_I:
			if (mode == GLFW_MOD_SHIFT) {
				t -= 1;
			}
			else {
				t += 1;
			}
			break;
		case GLFW_KEY_J:
			if (mode == GLFW_MOD_SHIFT) {
				l += 1;
			}
			else {
				l -= 1;
			}
			break;
		case GLFW_KEY_K:
			if (mode == GLFW_MOD_SHIFT) {
				b -= 1;
			}
			else {
				b += 1;
			}
			break;
		case GLFW_KEY_L:
			if (mode == GLFW_MOD_SHIFT) {
				r -= 1;
			}
			else {
				r += 1;
			}
			break;
		case GLFW_KEY_U:
			if (mode == GLFW_MOD_SHIFT) {
				n = std::max(n - 0.2, 0.1);
			}
			else {
				n = std::min(n + 0.2, f - 0.1);
			}
			break;
		case GLFW_KEY_O:
			if (mode == GLFW_MOD_SHIFT) {
				f = std::max(f - 0.2, n + 1.0);
			}
			else {
				f += 0.2;
			}
			break;
		case GLFW_KEY_B:
			if (mode == GLFW_MOD_SHIFT) {
				dist = std::max(dist - 0.2, 0.1);
			}
			else {
				dist += 0.2;
			}
			break;
		case GLFW_KEY_Z:
			if (mode == GLFW_MOD_SHIFT) {
				fovy_work = std::max(fovy_work - 0.2, 0.3);
			}
			else {
				fovy_work = std::min(fovy_work + 0.2, 3.0);
			}
			break;
		case GLFW_KEY_X:
			if (mode == GLFW_MOD_SHIFT) {
				aspect_work = std::max(aspect_work - 0.05, 0.01);
			}
			else {
				aspect_work += 0.05;
			}
			break;

		case GLFW_KEY_ESCAPE:
			initWorkPars();
			break;
		default:
			break;
		}
	}
}

// ���������� ������� ���������
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	dist += yoffset;
}

// ���������� ������� ������ ����
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT) {
		if (action == GLFW_PRESS)
			LMBpressed = true;
		else if (action == GLFW_RELEASE) {
			LMBpressed = false;
		}
	}
}

int main() {
	glfwInit(); // ������������� GLFW
	// �������� ����������� ��������� ������ OpenGL.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // ����� �� ���������� �����
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // ����� ����� ���������� �����
	// ���������� ������ �������� ��������� ������ ��� ������������� � ����� �������
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// ������� ����
	GLFWwindow* window = glfwCreateWindow(800, 600, "Task 7. Grigoriev", NULL, NULL);
	if (window == NULL) { // ���� ������ �� ���� �� �������
		std::cout << "����� glfwCreateWindow ���������� ��������." << std::endl;
		glfwTerminate(); // ��������� ������ GLFW
		return -1; // ��������� ���������
	}
	glfwMakeContextCurrent(window); // ������ ���� window �������� (�������)

	// ���������� ����������� ������� Resize
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	// ���������� ����������� ������� ������
	glfwSetKeyCallback(window, key_callback);
	// ���������� ����������� ��������� �������
	glfwSetCursorPosCallback(window, cursorPosSave_callback);
	// ���������� ����������� ��������� ����
	glfwSetScrollCallback(window, scroll_callback);
	// ���������� ����������� ������� ������ ����
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	// ������������� GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "�� ������� ��������� GLAD" << std::endl;
		glfwTerminate(); // ��������� ������ GLFW
		return -1; // ��������� ���������
	}

	// �������� �������� ��������� � ����
	// (0, 0) - ���������� ������ ������� ����, 800x600 - ������� ���� � ��������
	glViewport(0, 0, 800, 600);

	////=====================================================================
	//// ��������� ������
	////=====================================================================
	//const char *vertexShaderSource =
	//	"#version 330 core\n"
	//	"layout (location = 0) in vec3 position;\n"
	//	"uniform mat4 clipView;\n"
	//	"void main() {\n"
	//	" gl_Position = clipView * vec4(position, 1.0);\n"
	//	"}\0";
	////=====================================================================
	//GLuint vertexShader; // ��������� ������ - ��������� ������
	//vertexShader = glCreateShader(GL_VERTEX_SHADER); // ������� ������
	//// ����������� �������� ��� � ���������� �������
	//glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	//glCompileShader(vertexShader); // ����������� ������
	GLint success; // ��������� ����������
	//// ����������� ������ ���������� ������� � ���������� success
	//glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	//if (!success) { // ���� ���������� ������ � �������
	//	GLchar infoLog[512]; // ������� ��������� ��� ��������� �� ������
	//	glGetShaderInfoLog(vertexShader, 512, NULL, infoLog); // ����������� ���������
	//	// ������� ��������� �� ������ �� �����
	//	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	//}

	////======================================================
	//// ����������� ������
	////======================================================
	//const char *fragmentShaderSource =
	//	"#version 330 core\n"
	//	"out vec4 color;\n"
	//	"uniform vec3 pathColor;\n"
	//	"void main() {\n"
	//	" color = vec4(pathColor, 1.0f);\n"
	//	"}\n\0";

	////=======================================================
	//GLuint fragmentShader; // ��������� ������ - ����������� ������
	//fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); // ������� ������
	//													 // ����������� �������� ��� � ���������� �������
	//glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	//glCompileShader(fragmentShader); // ����������� ������
	//								 // ����������� ������ ���������� ������� � ��������� ����� ���������� success
	//glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	//if (!success) { // ���� ���������� ������ � �������
	//	GLchar infoLog[512]; // ������� ��������� ��� ��������� �� ������
	//	glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog); // ����������� ���������
	//															// ������� ��������� �� ������ �� �����
	//	std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	//}
	shader vertexShader("Vertex.glsl", GL_VERTEX_SHADER); // ��������� ������
	shader fragmentShader("Fragment.glsl", GL_FRAGMENT_SHADER); // ����������� ������
	//// ��������� ���������
	//GLuint shaderProgram; // ������������� ��������� ���������
	//shaderProgram = glCreateProgram(); // ������� ����������� ������
	//glAttachShader(shaderProgram, vertexShader.shaderID); // ������������ ��������� ������
	//glAttachShader(shaderProgram, fragmentShader.shaderID); // ����������� ������
	//glLinkProgram(shaderProgram); // ���������� ���������
	//// ����������� ������ ���������� ��������� ��������� � ���������� success
	//glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	//if (!success) { // ���� ���������� ������ � �������
	//	GLchar infoLog[512]; // ������� ��������� ��� ��������� �� ������
	//	glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog); // ����������� ���������
	//															// ������� ��������� �� ������ �� �����
	//	std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
	//}

	// ��������� ���������
	program shaderProgram(vertexShader, fragmentShader);

	// �������� ��������� ��������
	vertexShader.clear();
	fragmentShader.clear();

	//// ����������� � ��������� shaderProgram ������������ ���������� pathColor
	//GLint pathColorLocation = glGetUniformLocation(shaderProgram, "pathColor");
	//// ����������� � ��������� shaderProgram ������������ ���������� clipView
	//GLint clipViewLocation = glGetUniformLocation(shaderProgram, "clipView");

	// ����������� ������������� uniform-����������
	shaderProgram.useUniform("pathColor");
	shaderProgram.useUniform("clipView");
	shaderProgram.useUniform("modelView");
	shaderProgram.useUniform("modelInv");
	shaderProgram.useUniform("lightPos");
	shaderProgram.useUniform("viewPos");
	shaderProgram.useUniform("light.ambient");
	shaderProgram.useUniform("light.diffuse");
	shaderProgram.useUniform("light.specular");

	shaderProgram.useUniform("light2Pos");
	shaderProgram.useUniform("light2.ambient");
	shaderProgram.useUniform("light2.diffuse");
	shaderProgram.useUniform("light2.specular");

	// ��������� ������ ��� ��������� �����
	fragmentShader = shader("LightVertex.glsl", GL_VERTEX_SHADER);
	// ����������� ������ ��� ��������� �����
	fragmentShader = shader("LightFragment.glsl", GL_FRAGMENT_SHADER);
	// ��������� ��������� ��� ��������� �����
	program lightShaderProgram(vertexShader, fragmentShader);
	// �������� ��������� ��������
	vertexShader.clear();
	fragmentShader.clear();
	// ������������� uniform-���������� ��� ����� ��������� ���������.
	lightShaderProgram.useUniform("clipView");
	lightShaderProgram.useUniform("pathColor");

	//==========================================================
	// ����� �������� ������ ��� ��������� ��������� �����
	//==========================================================
	GLfloat lightVertices[] = {
		-0.1f, 0.f, 0.f,
		0.1f, 0.f, 0.f,
		0.f, 0.1f, 0.f,
		0.f, -0.1f, 0.f,
		0.f, 0.f, 0.1f,
		0.f, 0.f, -0.1f,
		0.07071f, 0.07071f, 0.f,
		-0.07071f, -0.07071f, 0.f,
		-0.07071f, 0.07071f, 0.f,
		0.07071f, -0.07071f, 0.f,
		0.07071f, 0.f, 0.07071f,
		-0.07071f, 0.f, -0.07071f,
		-0.07071f, 0.f, 0.07071f,
		0.07071f, 0.f, -0.07071f,
		0.f, 0.07071f, 0.07071f,
		0.f, -0.07071f, -0.07071f,
		0.f, -0.07071f, 0.07071f,
		0.f, 0.07071f, -0.07071f,
		0.05774f, 0.05774f, 0.05774f,
		-0.05774f, -0.05774f, -0.05774f,
		-0.05774f, -0.05774f, 0.05774f,
		0.05774f, 0.05774f, -0.05774f,
		-0.05774f, 0.05774f, 0.05774f,
		0.05774f, -0.05774f, -0.05774f,
		0.05774f, -0.05774f, 0.05774f,
		-0.05774f, 0.05774f, -0.05774f
	};
	GLuint lightVertexArray; // ������ ���������� �������
	// ������� ��������� ������, ������������� �������� ����������� vertexArray
	glGenVertexArrays(1, &lightVertexArray);
	glBindVertexArray(lightVertexArray); // ������ �������� ��������� ������

	GLuint lightVertexBuffer; // ������������� ��������� �������
	// ������� �������� ������, ������������� �������� ����������� vertexBuffer
	glGenBuffers(1, &lightVertexBuffer);
	// �������� vertexBuffer � GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, lightVertexBuffer);
	// � �����, ����������� � GL_ARRAY_BUFFER �������� ���������� vertices
	glBufferData(GL_ARRAY_BUFFER, sizeof(lightVertices), lightVertices, GL_STATIC_DRAW);
	// �������� ������������ ��������� ���������� ������� � ��������� ������
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0); // ��������� ��������� 0 ��� �������
	glBindBuffer(GL_ARRAY_BUFFER, 0); // ������� ��������� �������
	glBindVertexArray(0); // ���������� ���������� �������

	// ����������� ��������� ����� �� ������ ��������� � ����� (0, 0, 5)
	lightM = glm::translate(glm::vec3(0, 0, 5));
	light2M = glm::translate(glm::vec3(7, 5, -4));

	//==============================================
	// ����� �������� ������ ��� ���������
	//==============================================
	//GLfloat vertices[] = {
	//	-0.5f, -0.5f, 0.0f,
	//	0.5f, -0.5f, 0.0f,
	//	0.0f, 0.5f, 0.0f
	//};
	//GLuint vertexArray; // ������ ���������� �������
	//					// ������� ��������� ������, ������������� �������� ����������� vertexArray
	//glGenVertexArrays(1, &vertexArray);
	//glBindVertexArray(vertexArray); // ������ �������� ��������� ������

	//GLuint vertexBuffer; // ������������� ��������� �������
	//					 // ������� �������� ������, ������������� �������� ����������� vertexBuffer
	//glGenBuffers(1, &vertexBuffer);
	//// �������� vertexBuffer � GL_ARRAY_BUFFER
	//glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	//// � �����, ����������� � GL_ARRAY_BUFFER �������� ���������� vertices
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//// �������� ������������ ��������� ���������� ������� � ��������� ������
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	//glEnableVertexAttribArray(0); // ��������� ��������� 0 ��� �������
	//glBindBuffer(GL_ARRAY_BUFFER, 0); // ������� ��������� �������
	//glBindVertexArray(0); // ���������� ���������� �������

	readFromFile("triangle.txt");
	// ��������� ���� � �������� �������
	while (!glfwWindowShouldClose(window)) { // ���� ���� window �� ������ ���������
		glClearColor(0.2f, 0.4f, 0.3f, 1.0f); // ��������� ���� �������
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);; // ������� ����� �������� ������ � ������� ������������

		glm::mat4 move = glm::rotate((float)glfwGetTime() * glm::radians(10.0f), glm::vec3(0.0f,1.0f, 1.0f));
		glm::mat4 lightM1 = move * lightM;

		shaderProgram.use(); // ��������� ��������� shaderProgram ������ ��������
		//glBindVertexArray(vertexArray); // ������ �������� ��������� ������
		//glLineWidth(6);
		//glDrawArrays(GL_LINE_STRIP, 0, 3); // ��������� ������ ������������
		//glBindVertexArray(0); // ��������� ��������� ������

		glm::mat4 proj; // ������� �������� � ������������ ���������
		switch (pType) {
		case Ortho: // ������������� ��������
			proj = glm::ortho(l, r, b, t, n, f);
			break;
		case Frustum: // ������������� �������� � Frustum
			proj = glm::frustum(l, r, b, t, n, f);
			break;
		case Perspective: // ������������� �������� � Perspective
			proj = glm::perspective(fovy_work, aspect_work, n, f);
			break;
		}
		glm::mat4 C = proj * T; // ������� �������� �� ������� ��������� � ������������ ���������
		shaderProgram.setUniform("light.ambient", glm::vec3(lightAmbientR, lightAmbientG, lightAmbientB));
		shaderProgram.setUniform("light.diffuse", glm::vec3(lightDiffuseR * lightDifSpecMult
								, lightAmbientG * lightDifSpecMult, lightDiffuseB * lightDifSpecMult));
		shaderProgram.setUniform("light.specular", glm::vec3(lightSpecularR * lightDifSpecMult
								, lightSpecularG * lightDifSpecMult, lightSpecularB * lightDifSpecMult));
		shaderProgram.setUniform("lightPos", glm::vec3(lightM1 * glm::vec4(0, 0, 0, 1)));
		shaderProgram.setUniform("light2.ambient", glm::vec3(light2AmbientR, light2AmbientG, light2AmbientB));
		shaderProgram.setUniform("light2.diffuse", glm::vec3(light2DiffuseR * lightDifSpecMult
								, light2DiffuseG * lightDifSpecMult, light2DiffuseB * lightDifSpecMult));
		shaderProgram.setUniform("light2.specular", glm::vec3(light2SpecularR * lightDifSpecMult
								, light2SpecularG * lightDifSpecMult, light2SpecularB * lightDifSpecMult));
		shaderProgram.setUniform("lightPos", glm::vec3(light2M * glm::vec4(0, 0, 0, 1)));

		shaderProgram.setUniform("viewPos", glm::vec3(glm::inverse(T) * glm::vec4(0, 0, 0, 1)));
		shaderProgram.useUniform("material.ambient");
		shaderProgram.useUniform("material.diffuse");
		shaderProgram.useUniform("material.specular");
		shaderProgram.useUniform("material.shininess");
		glEnable(GL_DEPTH_TEST);
		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		for (int k = 0; k < models.size(); k++) { // ���� �� ��������
			std::vector<mesh> figure = models[k].figure; // ������ ������� ���������� �������
			glm::mat4 TM = C * models[k].modelM; // ������� ������ �������������� ������
			// ��������� ��������� ������� TM � ���������� clipView ��������� ���������
			shaderProgram.setUniform("clipView", TM);
			shaderProgram.setUniform("modelView", models[k].modelM);
			shaderProgram.setUniform("modelInv", glm::transpose(glm::inverse(models[k].modelM)));

			for (int i = 0; i < figure.size(); i++) {
				shaderProgram.setUniform("material.ambient", figure[i].material.ambient);
				shaderProgram.setUniform("material.diffuse", figure[i].material.diffuse);
				shaderProgram.setUniform("material.specular", figure[i].material.specular);
				shaderProgram.setUniform("material.shininess", figure[i].material.shininess);
				glBindVertexArray(figure[i].vertexArray); // ������ �������� ��������� ������ i-� �������
				// ��������� ������ ������������� �� ������ ��������
				glDrawElements(GL_TRIANGLES, figure[i].indices.size(), GL_UNSIGNED_INT, 0);
				glBindVertexArray(0); // ��������� ��������� ������
			}
		}
		lightShaderProgram.use(); // ������ �������� ��������� ��� ��������� �����
								  // ������� �������� � ������������ ���������
		lightShaderProgram.setUniform("clipView", C * lightM1);

		lightShaderProgram.setUniform("pathColor", glm::vec3( lightAmbientR + lightAmbientG + lightAmbientB
															, lightDiffuseR + lightDiffuseG + lightDiffuseB
															, lightSpecularR + lightSpecularG + lightSpecularB));

		glBindVertexArray(lightVertexArray); // ������ �������� ��������� ������
		glDrawArrays(GL_LINES, 0, 26); // ������ 13 �������� (� ������� 26 �����)

		lightShaderProgram.setUniform("clipView", C * light2M);
		lightShaderProgram.setUniform("pathColor", glm::vec3( light2AmbientR + light2AmbientG + light2AmbientB
															, light2DiffuseR + light2DiffuseG + light2DiffuseB
															, light2SpecularR + light2SpecularG + light2SpecularB));
		glDrawArrays(GL_LINES, 0, 26); // ������ 13 �������� ������� ��������� ����� (� ������� 26 �����)
		glBindVertexArray(0); // ��������� ��������� ������

		glfwSwapBuffers(window); // �������� ������� ������ �����������
		glfwPollEvents(); // ���������, ��������� �� �����-�� �������
	}

	glfwTerminate(); // ��������� ������ GLFW
	return 0;
}