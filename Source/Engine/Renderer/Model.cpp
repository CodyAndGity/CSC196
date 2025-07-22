#include "Model.h"
#include "Renderer.h"
namespace bonzai {

	/// <summary>
	/// Draws the model by connecting its points with lines using the specified renderer.
	/// </summary>
	/// <param name="renderer">The Renderer object used to draw the model.</param>
	void Model::draw(Renderer& renderer, const vec2& position, float rotation, float scale) {
		if (points.size() < 2) return; // need at least 2 points to draw a line
		renderer.setColor(color.r, color.g, color.b);
		//draw through all points
		for (int i=0; i < points.size(); i++) {
			 vec2 p1 = points[i].rotate(math::degToReg(rotation))*scale+position;
			 vec2 p2 = points[(i + 1) % points.size()].rotate(math::degToReg(rotation)) * scale +position; // wrap around to first point
			renderer.drawLine(p1.x, p1.y, p2.x, p2.y);
		}
	}

	/// <summary>
	/// Draws the model using the specified renderer and transformation.
	/// </summary>
	/// <param name="renderer">The renderer used to draw the model.</param>
	/// <param name="transform">The transformation to apply, including position, rotation, and scale.</param>
	void Model::draw(Renderer& renderer, const Transform& transform){
		draw(renderer, transform.position, transform.rotation, transform.scale);
	}

}