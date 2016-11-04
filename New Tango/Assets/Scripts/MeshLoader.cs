using UnityEngine;
using System.Collections;

public class MeshLoader : MonoBehaviour {


	// Use this for initialization
	void Start () {
		GameObject obj = (GameObject) Object.Instantiate(Resources.Load("Mesh_003"));
		//obj.transform.localScale = new Vector3(100.0f, 100.0f, 100.0f);
		obj.transform.localRotation = Quaternion.Euler (-90.0f, 180.0f, 0.0f);

		Transform[] ts = obj.GetComponentsInChildren<Transform>();
		foreach (Transform t in ts) {
			t.gameObject.AddComponent <MeshCollider>();
		}
			

		Debug.Log ("TEST");
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
