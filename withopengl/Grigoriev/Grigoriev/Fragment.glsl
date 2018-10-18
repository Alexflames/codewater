#version 330 core
in vec3 fragPos; // координаты точки
in vec3 fragNorm; // координаты нормали в точке

struct Light {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

out vec4 color;

uniform Light light; // компоненты света
uniform vec3 lightPos; // координаты источника света
uniform Light light2; // компоненты света
uniform vec3 light2Pos; // координаты источника света

uniform vec3 viewPos; // координаты точки наблюдения
uniform Material material;

void main() {
	// нормализуем полученный вектор нормали
	vec3 norm = normalize(fragNorm);
	// получаем нормализованный вектор направления на источник света
	vec3 lightDir = normalize(lightPos - fragPos);
	// вычисляем косинус угла между полученными векторами
	float cosTheta = max(dot(norm, lightDir), 0.0);
	
	float powOfCos; // коэффициент бликовой освещенности
	if (cosTheta > 0.0) { // если cosTheta <= 0, бликовая освещенность равна 0
		// получаем нормализованный вектор направления в точку наблюдения
		vec3 viewDir = normalize(viewPos - fragPos);
		// получаем вектор отраженного света
		vec3 lightDirR = reflect(-lightDir, norm);
		powOfCos = pow(max(dot(viewDir, lightDirR), 0.0), material.shininess);
	}
	else
	powOfCos = 0.0;
	
	// получаем нормализованный вектор направления на источник света
	vec3 lightDir2 = normalize(light2Pos - fragPos);
	// вычисляем косинус угла между полученными векторами
	float cosTheta2 = max(dot(norm, lightDir2), 0.0);
	
	float powOfCos2; // коэффициент бликовой освещенности
	if (cosTheta2 > 0.0) { // если cosTheta <= 0, бликовая освещенность равна 0
		vec3 viewDir = normalize(viewPos - fragPos);
		// получаем вектор отраженного света
		vec3 lightDirR2 = reflect(-lightDir2, norm);
		powOfCos2 = pow(max(dot(viewDir, lightDirR2), 0.0), material.shininess);
	}
	else
	powOfCos2 = 0.0;
	
	vec3 ambient = light.ambient * material.ambient;
	vec3 diffuse = light.diffuse * cosTheta * material.diffuse;
	vec3 specular = light.specular * powOfCos * material.specular;
	
	vec3 ambient2 = light2.ambient * material.ambient;
	vec3 diffuse2 = light2.diffuse * cosTheta2 * material.diffuse;
	vec3 specular2 = light2.specular * powOfCos2 * material.specular;

	vec3 result = ambient + diffuse + specular + ambient2 + diffuse2 + specular2;
	
	color = vec4(result, 1.0);
}