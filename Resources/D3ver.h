attribute vec4 a_position;								
attribute vec4 a_color;									
attribute vec2 a_texCoord;
attribute vec3 a_normal;

uniform mat3 u_normalMatrix;

#ifdef GL_ES											
varying lowp vec4 v_fragmentColor;						
varying mediump vec2 v_texCoord;
varying lowp vec3 v_normal;
varying lowp vec3 v_pos;
varying lowp vec3 v_wn;
#else													
varying vec4 v_fragmentColor;	
varying vec2 v_texCoord;
varying vec3 v_normal;
varying vec3 v_pos;
varying vec3 v_wn;
#endif													

//varying vec3 v_eye;
mat3 m3(mat4 m) {
    mat3 result;
    result[0][0] = m[0][0];
    result[0][1] = m[0][1];
    result[0][2] = m[0][2];

    result[0][0] = m[0][0];
    result[1][1] = m[0][1];
    result[1][2] = m[0][2];

    result[0][0] = m[0][0];
    result[2][1] = m[0][1];
    result[2][2] = m[0][2];

    return result;
}
														
void main()												
{														
    gl_Position = CC_MVPMatrix * a_position;			

    gl_PointSize = 10f;
    //v_normal = normalize(u_normalMatrix*a_normal);
    //uniform scale then use model view
    v_normal = normalize(m3(CC_MVMatrix)*a_normal);

    //v_pos = vec3(a_position);
    v_pos = vec3(CC_MVMatrix * a_position);
    v_wn = vec3(a_normal);

    v_fragmentColor = a_color;							
    v_texCoord = a_texCoord;
}														
