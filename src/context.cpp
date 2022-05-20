#include "context.h"
#include "buffer.h"

ContextUPtr Context::Create()
{
    auto context = ContextUPtr (new Context());
    if (!context->Init())
        return nullptr;

    return std::move(context);
}

bool Context::Init()
{
  float vertices[] = {
    
    0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
    0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
    -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f
  };
  
  uint32_t indices[] = {
    0, 1, 3,
    1, 2, 3,
  };


  m_vertexLayout = VertexLayout::Create();  
  
  m_vertexBuffer = Buffer::CreateWithData(GL_ARRAY_BUFFER, GL_STATIC_DRAW, vertices, sizeof(float) * 24);
  
  //m_vertexLayout->SetAttrib(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
  m_vertexLayout->SetAttrib(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
  m_vertexLayout->SetAttrib(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, sizeof(float) * 3);
  
  m_indexBuffer = Buffer::CreateWithData(GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW, indices, sizeof(float) * 6);
  
  //ShaderPtr vertexShader = Shader::CreateFromFile("./shader/simple.vs", GL_VERTEX_SHADER);
  //ShaderPtr fragmentShader = Shader::CreateFromFile("./shader/simple.fs", GL_FRAGMENT_SHADER);
  ShaderPtr vertexShader = Shader::CreateFromFile("./shader/per_vertex_color.vs", GL_VERTEX_SHADER);
  ShaderPtr fragmentShader = Shader::CreateFromFile("./shader/per_vertex_color.fs", GL_FRAGMENT_SHADER);

  if (!vertexShader || !fragmentShader)
  {
      return false;
  }
  SPDLOG_INFO("VERTEX SHADER ID : {}", vertexShader->Get());
  SPDLOG_INFO("fragment shader id: {}", fragmentShader->Get());

  m_program = Program::Create({fragmentShader, vertexShader});
  if (!m_program)
    return false;

  SPDLOG_INFO("program id : {}", m_program->Get());   //link shader to program

  //auto loc = glGetUniformLocation(m_program->Get(), "color");  // uniform variable setting
  //m_program->Use();
  //glUniform4f(loc, 1.0f, 1.0f, 0.0f, 1.0f);


  glClearColor(0.0f,0.1f,0.2f,0.0f);
  
  //uint32_t vao = 0;
  //glGenVertexArrays(1, &vao);
  //glBindVertexArray(vao);

  return true;
}

void Context::Render()
{
  /*
  glClear(GL_COLOR_BUFFER_BIT);
  static float time = 0.0f;
  float t= sinf(time) * 0.5f + 0.5f;
  auto loc = glGetUniformLocation(m_program->Get(), "color");
  m_program->Use();
  glUniform4f(loc, t*t, 2.0f*t*(1.0f-t),  (1.0f-t)*(1.0f-t), 1.0f);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  time += 0.016f;
*/

  
  glClear(GL_COLOR_BUFFER_BIT);
  m_program->Use();
  //glDrawArrays(GL_POINTS, 0, 1);
  //glDrawArrays(GL_TRIANGLES, 0, 6);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  
}