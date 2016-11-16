using UnityEngine;
using System.Collections;

public class MeshLoader : MonoBehaviour {

	public string meshName = "Nothing";
	string lastMeshName;
	GameObject obj;

	// Use this for initialization
	void Start () {

		//obj = (GameObject)Object.Instantiate (Resources.Load (meshName));
		//obj.transform.localScale = new Vector3(100.0f, 100.0f, 100.0f);
		//obj.transform.localRotation = Quaternion.Euler (-90.0f, 180.0f, 0.0f);

		//Transform[] ts = obj.GetComponentsInChildren<Transform> ();
		//foreach (Transform t in ts) {
			//t.gameObject.AddComponent <MeshCollider> ();
		//}

		//Debug.Log ("TEST");
	}
	
	// Update is called once per frame
	void Update () {
		if (meshName != "Nothing" && meshName != lastMeshName) {
			obj = (GameObject)Object.Instantiate (Resources.Load (meshName));
			//obj.transform.localScale = new Vector3(100.0f, 100.0f, 100.0f);
			obj.transform.localRotation = Quaternion.Euler (-90.0f, 180.0f, 0.0f);

			Transform[] ts = obj.GetComponentsInChildren<Transform> ();
			foreach (Transform t in ts) {
				t.gameObject.AddComponent <MeshCollider> ();
			}
		}

		if (meshName != null) {
			lastMeshName = meshName;
		}

	}

	void OnGUI(){
		//GUI.Label(new Rect(10, 10, 100, 20), meshName);
	}
}
