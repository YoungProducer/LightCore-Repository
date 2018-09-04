#shader fragment
#version 330 core
out vec4 color;

in vec3 fragPos;  
in vec3 normal;  
  
uniform vec3 u_lightPos; 
uniform vec3 u_viewPos;
uniform vec3 u_lightColor;
uniform vec3 u_objectColor;

void main()
{

	vec3 m_fragPos = vec3(1.2f, 1.0f, 2.0f);
	vec3 m_normal = vec3(0.0f, 0.0f, 0.0f);
    // Ambient
    float m_ambientStrength = 0.1f;
    vec3 m_ambient = m_ambientStrength * u_lightColor;
  	
    // Diffuse 
    vec3 m_norm = normalize(m_normal);
    vec3 m_lightDir = normalize(u_lightPos - m_fragPos);
    float m_diff = max(dot(m_norm, m_lightDir), 0.0);
    vec3 m_diffuse = m_diff * u_lightColor;
    
    // Specular
    float m_specularStrength = 0.5f;
    vec3 m_viewDir = normalize(u_viewPos - m_fragPos);
    vec3 m_reflectDir = reflect(-m_lightDir, m_norm);  
    float m_spec = pow(max(dot(m_viewDir, m_reflectDir), 0.0), 32);
    vec3 m_specular = m_specularStrength * m_spec * u_lightColor;  
        
    vec3 m_result = (m_ambient + m_diffuse + m_specular) * u_objectColor;
    color = vec4(m_result, 1.0f);
} 