using UnityEngine;
using System.Collections;

public class setRenderQueue : MonoBehaviour {

	protected int[] _queues = new int[]{ 3000 };

	protected void Awake(){
		Renderer[] renders = GetComponentsInChildren<Renderer> ();
		for (int i = 0; i < renders.Length; i++) {
			Material[] materials = renders [i].materials;
			for (int j = 0; j < materials.Length; j++) {
				materials [j].renderQueue = 3000;
			}
		}
			

	}
}
