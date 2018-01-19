cbuffer MatrixBuffer
{
   matrix worldMatrix;
   matrix viewMatrix;
   matrix projectionMatrix;
};

struct VertexInputType
{
    float4 position:POSITION;
    float2 tex : TEXCOORD0;
};

struct PixelInputType
{
  float4 position:SV_POSITION;
  float2 tex:TEXCOORD0;
};

PixelInputType ColorVertexShader(VertexInputType input)
{
   PixelInputType output;
   
   input.position.w = 1.0f;
   
   output.position = mul(input.position,worldMatrix);
   output.position = mul(output.position,viewMatrix);
   output.position = mul(output.position,projectionMatrix);
   
   output.color = input.color;
   
   return output;
};